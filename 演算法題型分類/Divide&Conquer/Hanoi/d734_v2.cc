/* 給定Ｎ個圓盤(編號１-Ｎ)，這些圓盤初始起點的柱子編號 和 終點的目標柱子編號，在搬動最少次數的限制下輸出搬動的過程？
 * 解題關鍵：分治法(遞迴)，練習找到問題和子問題的對應＋重複利用已經學會的函數 ... 為 b592 鋪墊
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
const int SUM='a'+'b'+'c';
char now[MaxN];
char stp[MaxN];

/* 一般版本的河內塔搬移過程 */
void Hanoi_Normal(int ths,char s,char e,char t){
	if(ths) Hanoi_Normal(ths-1,s,t,e);
	printf("ring %d : %c -> %c\n",ths+1,s,e);
	now[ths]=e;
	if(ths) Hanoi_Normal(ths-1,t,e,s);
}
/* 混亂版本的遞迴：將編號 ths 的圓盤搬移到 to 柱，根據這個圓盤是否"已經"在目標柱子的２種情況討論？
 * (1) 該圓盤的位置不存在目標位置：需要把編號小於 ths 的所有圓盤都集中到"暫存區"，之後再集中到目標位置。
 * 	   排除法：暫存區的柱子編號＝不是目標位置也不是目前第 ths 號圓盤的位置
 * 	   子問題：編號小於 ths 的所有圓盤先集中到"暫存區"，呼叫混亂版本的遞迴處理編號 ths-1 的圓盤的目標位置改為"暫存區"
 *            編號小於 ths 的所有圓盤再集中到"目標位置"＝呼叫一般版本的遞迴
 * (2) 該圓盤的位置"已經"存在目標位置：呼叫混亂版本的遞迴處理子問題，範圍縮減到 ths-1 
 */
void Hanoi_Special(int ths,char to,int& ans,int rhs=0){
	if(now[ths]!=to){
		if(ths)
			Hanoi_Special(ths-1,SUM-now[ths]-to,ans);
		printf("ring %d : %c -> %c\n",ths+1,now[ths],to);
		ans+=1; 
		now[ths]=to;
		if(ths){
			Hanoi_Normal(ths-1,now[ths-1],to,SUM-now[ths-1]-to);
			ans+=(1<<ths)-1;
		}
		return;
	}
	if(ths)
		Hanoi_Special(ths-1,to,ans);
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
		/* 只有第一次需要從混亂狀態"集中"到某一根柱子的部分需要寫新版本的河內塔
		 * "集中狀態"形成後若需要再逐一分發到其他柱子時就可以用一般版本的河內塔
		 */
		int ans=0;
		/* 從最底層開始比對，找到需要搬移的圓盤中編號最大者，呼叫處理"混亂狀態集中到同一個柱子"的函數版本 */
		for(N-=1; N>=0 and now[N]==stp[N]; N-=1);
		if(N>0){ 
			Hanoi_Special(N-1,SUM-now[N]-stp[N],ans);
			printf("ring %d : %c -> %c\n",N+1,now[N],stp[N]);
			ans+=1;
		}
		/* 優化：小於Ｎ的所有圓盤都集中在某一根柱子的狀態已經形成
		 *      從目前底層第Ｎ號圓盤逐一往上檢查，若現在位置 ≠ 目標位置，需要把小於Ｎ的圓盤"再集中到暫存區"
		 *      上述的要求可以重複利用一般版本的河內塔函數，且該次累加的方法數可以從公式中得知(不需遞迴處理)
		 */
		for(N-=1; N>=0; N-=1){
			if(now[N]!=stp[N]){
				if(N>0){
					Hanoi_Normal(N-1,now[N],SUM-now[N]-stp[N],stp[N]);
					ans+= (1<<N)-1;
				}
				printf("ring %d : %c -> %c\n",N+1,now[N],stp[N]);
				ans+=1;
			}
		}
		printf("%d\n",ans);
	}
}