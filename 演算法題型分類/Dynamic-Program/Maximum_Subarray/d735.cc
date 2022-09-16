/* 給定邊長為Ｎ的矩陣，輸出矩形範圍內最小的子區域總和(至少選一個數字)？
 * 解題核心：column squash
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
int num[MaxN+1][MaxN+1];
int prS[MaxN+1][MaxN+1]={};
int v[MaxN+1]={};
int main(){
	int N;
	while( cin>>N ){
		// input
		for(int r=1; r<=N; r++)
			for(int c=1; c<=N; c++)
				cin>>num[r][c];
		// prefix-sum for each row
		for(int r=1; r<=N; r++)
			for(int c=1; c<=N; c++)
				prS[r][c]=prS[r][c-1]+num[r][c];
		// brute-force
		int ans=num[1][1];
		for(int Lc=1; Lc<=N; Lc++)
			for(int Rc=Lc; Rc<=N; Rc++){
				// 代表每一個 row 的 Lc:Rc 之間數字壓縮成一個
				for(int r=1; r<=N; r++)
					v[r]=prS[r][Rc]-prS[r][Lc-1];
				int maxv=0;
				int prSv=0;
				for(int r=1; r<=N; r++){
					prSv+=v[r];
					ans=min(ans,prSv-maxv);
					maxv=max(maxv,prSv);
				}
			}
		cout<<ans<<'\n';
	}
}