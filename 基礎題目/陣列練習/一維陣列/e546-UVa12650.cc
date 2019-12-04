#include<bits/stdc++.h>
using namespace std;

const int MaxR=1e4;
const int MaxN=1e4; // 1 ≤ R ≤ N ≤ 10000
int turn[MaxN+1];
int main(){
	int R, N, x;
	for(int caseI=1;scanf("%d %d",&N,&R)==2;caseI++){
		for(int i=0;i<R;i++)
			scanf("%d",&x), turn[x]=caseI;
		int cnt=0;
		for(int i=1;i<=N;i++)
			if(turn[i]!=caseI)
				printf("%d ",i), 
				cnt++;
		(cnt==0)? puts("*"): puts("");
	}
}