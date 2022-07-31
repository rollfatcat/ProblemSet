/* 給定Ｎ個數字，選取２段連續的區間和(２段間可以不連續)，最大化２段區間和的加總
 * 解題關鍵：動態規劃
 * 枚舉切點，拆分為鄉鄰的２段範圍，找到範圍內的最大子區間和
 * 狀態定義與狀態轉移：
 *  L2R[n] = １到ｎ範圍內的最大子區間和, 由左到右更新
 *  R2L[n] = Ｎ到ｎ範圍內的最大子區間和, 由右到左更新
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxS=1e3;
int num[MaxN+1];
int L2R[MaxN+2];
int R2L[MaxN+2];
int main(){
	int N, M, ans;
	while( scanf("%d %d",&N,&M)!=EOF ){
		for(int n=1; n<=N; n++)
			scanf("%d",&num[n]);
		L2R[0]=R2L[N+1]=0;
		for(int n=1; n<=N; n++)
			L2R[n]=max(0,L2R[n-1])+num[n];
		for(int n=N; 0< n; n--)
			R2L[n]=max(0,R2L[n+1])+num[n];
		for(int n=N; 0< n; n--)
			R2L[n]=max(R2L[n],R2L[n+1]);
		ans=0;
		for(int n=1; n<=N; n++){
			L2R[n]=max(L2R[n],L2R[n-1]);
			ans=max(ans,L2R[n-1]+R2L[n]);
		}
		printf("%d\n",ans);
	}
}