/* 動態規劃＋線段樹：
 * 題目類似 a596 的概念, MaxCaseTｘMaxNｘMaxN > 1e8
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=50;
const int MaxN=3e4;
const int MaxA=1e5;
const int MaxB=1e5;
const int MaxC=1e3;
 
struct LINE{
	int st, ed, v;
	bool operator<(const LINE &rhs)const{ return st<rhs.st; }
} line[MaxN];
int ED[MaxN];
int DP[MaxN];
int EDcnt;
inline int lowbit(int x){ return x&-x; }
inline int Query(int pos,int v=0){
	for( ;pos>0;pos-=lowbit(pos))
		v=max(v,DP[pos]);
	return v;
}
inline void Addv(int pos,int v){
	for( ;pos<=EDcnt and DP[pos]<v;pos+=lowbit(pos))
		DP[pos]=v;
}
int main(){
	int caseT, N;
	scanf("%d",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d %d %d",&line[i].st,&line[i].ed,&line[i].v);
			ED[i+1]=line[i].ed=line[i].st+line[i].ed-1;
		}
		sort(line,line+N);
		sort(ED+1,ED+N+1);
		EDcnt=unique(ED,ED+N)-ED;
		fill(DP,DP+EDcnt,0);
 
		int tag, maxv, maxDP=0;
		for(int i=0;i<N;i++){
			tag=lower_bound(ED+1,ED+EDcnt+1,line[i].st)-ED;
			maxv=Query(tag-1)+line[i].v;
			maxDP=max(maxDP,maxv);
			tag=lower_bound(ED+1,ED+EDcnt+1,line[i].ed)-ED;
			Addv(tag,maxv);
		}
		printf("Case %d: %d\n",caseI,maxDP);
	}
}