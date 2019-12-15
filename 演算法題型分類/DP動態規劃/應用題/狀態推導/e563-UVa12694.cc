// e686. 11908 - Skyscraper  的弱化版
/* Ｎ≤ 20, 所以查詢『小於等於現在開始時間』的最大數量時可以Ｏ(Ｎ)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;
const int MaxN=20;
const int MaxF=10;
struct LINE{
	int s, f;
	bool operator<(const LINE &rhs)const{ return s<rhs.s; }
} line[MaxN+1];
int DP[MaxF+1];

int main(){
	int caseT, maxv, N;
	scanf("%d",&caseT);
	while(caseT--){
		N=0;
		while(scanf("%d %d",&line[N].s,&line[N].f) and line[N].f>0)
			N++;
		sort(line,line+N);
		fill(DP,DP+11,0);
		for(int i=0;i<N;i++){
			maxv=0;
			for(int j=1;j<=line[i].s;j++)
				maxv=max(maxv,DP[j]);
			DP[line[i].f]=max(DP[line[i].f],maxv+1);
		}
		for(int i=1;i<=10;i++)
			maxv=max(maxv,DP[i]);
		printf("%d\n",maxv);
	}
}
