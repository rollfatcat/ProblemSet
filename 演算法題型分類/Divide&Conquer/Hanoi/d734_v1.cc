/* 給定Ｎ個圓盤(編號１-Ｎ)，這些圓盤初始起點的柱子編號 和 終點的目標柱子編號，在搬動最少次數的限制下輸出搬動的過程？
 * 解題關鍵：分治法(遞迴)，練習找到問題和子問題的對應
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
const int SUM='a'+'b'+'c';
char now[MaxN];
char stp[MaxN];
/* 將編號 ths 的圓盤搬移到 to 柱，檢查這個圓盤是否"已經"在目標柱子？
 * (1) 該圓盤的位置不存在目標位置：需要把編號小於 ths 的所有圓盤都集中到"暫存區"，之後再集中到目標位置。
 * 	   排除法：暫存區的柱子編號＝不是目標位置也不是目前第 ths 號圓盤的位置
 * 	   子問題：編號小於 ths 的所有圓盤先集中到"暫存區"，呼叫遞迴處理編號 ths-1 的圓盤的目標位置改為"暫存區"
 *            編號小於 ths 的所有圓盤再集中到"目標位置"＝呼叫遞迴，同(2)
 * (2) 該圓盤的位置"已經"存在目標位置：呼叫遞迴處理子問題，範圍縮減到 ths-1 
 */
void Hanoi(int ths,char to,int& ans){
	if(now[ths]!=to){
		if(ths)
			Hanoi(ths-1,SUM-now[ths]-to,ans);
		printf("ring %d : %c -> %c\n",ths+1,now[ths],to);
		ans+=1;
		now[ths]=to;
	}
	if(ths)
		Hanoi(ths-1,to,ans);
}
int main(){
	int N, ans;
	while(scanf("%d\n",&N)!=EOF and N>0){
		for(int i=0;i<N;i++)
			scanf("%d",&now[i]), 
			now[i]+='a'-1;
		for(int i=0;i<N;i++)
			scanf("%d",&stp[i]), 
			stp[i]+='a'-1;
		int ans=0;
		for(N-=1; N>=0; N-=1)
			// 若將第Ｎ號圓盤不在目標位置＝需要從現在位置搬移過去
			if(now[N]!=stp[N]){
				// 確認所有小於Ｎ的圓盤都位於暫存區(不是目標位置也不是目前第Ｎ號圓盤的位置)
				if(N>0) Hanoi(N-1,SUM-now[N]-stp[N],ans);
				// 將第Ｎ號圓盤從現在位置搬移到目標位置
				printf("ring %d : %c -> %c\n",N+1,now[N],stp[N]);
				ans+=1;
			}
		printf("%d\n",ans);
	}
}