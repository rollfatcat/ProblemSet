/* 給定Ｎ個數字和Ｌ,Ｒ，可以透過執行「替換規則」，目的讓數列總和越小越好
 * 替換規則：由最左邊到某一格的數字都替換成Ｌ, 由最右邊到某一格的數字都替換成Ｒ
 * 解題關鍵：動態規劃，因為替換規則是必須從左或是從右側連續延伸所以更新順序拆分成左右２個部分
 * 狀態定義：dpL[ｎ] = 由左開始到第ｎ格時最小的總和， dpR[ｎ] = 由右開始到第ｎ格時最小的總和
 * 狀態轉移：替換規則提到操作必須是從左/右開始連續換成L/R，考慮到要不要選取第ｎ格數字
 * 		dpl[n] = max(dpl[n-1]+num[n], L*  n  )
 * 		dpr[n] = max(dpr[n+1]+num[n], R*(N-n))
 * 更新順序：枚舉 dpl 和 dpr 的總和搭配
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxW=1e9;
int num[MaxN];
long dpl[MaxN];
long dpr[MaxN];
int main(){
	int N, L, R;
	scanf("%d %d %d",&N,&L,&R);
	for(int n=0; n<N; n++)
		scanf("%d",&num[n]);
		
	dpl[ 0 ]=min(num[ 0 ],L);
	for(long n=1; n<N; n++)
		dpl[n]=min(dpl[n-1]+num[n],(n+1)*L);
	dpr[N-1]=min(num[N-1],R);
	for(long n=N-2; 0<=n; n--)
		dpr[n]=min(dpr[n+1]+num[n],(N-n)*R);
		
	long ans=min(dpl[N-1],dpr[0]);
	for(long n=1; n<N; n++)
		ans=min(ans,dpl[n-1]+dpr[n]);
	printf("%ld",ans);
}