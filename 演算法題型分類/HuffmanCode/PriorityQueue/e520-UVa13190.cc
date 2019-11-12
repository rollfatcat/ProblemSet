/* 利用PriorityQueue實現O(㏒Ｎ)的查詢
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=3e3;
const int MaxL=20;
struct ITEM{
	char name[MaxL];
	int intv=0;
} item[MaxN];
struct UNIT{
	int t, p;
	UNIT(int t=0,int p=0): t(t),p(p){};
	bool operator<(const UNIT rhs)const{
		return (t==rhs.t)? p>rhs.p:t>rhs.t;
	}
} now;
 
int main(){
	int caseT; // MaxCaseT=15
	int N;	   // MaxN=3e3
	int K;     // MaxK=1e4
 
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%d %d\n",&N,&K);
		priority_queue<UNIT,vector<UNIT>> PQ;
		for(int i=0;i<N;i++)
			scanf("%s %d",item[i].name,&item[i].intv),
			PQ.push(UNIT(item[i].intv,i));
		while(K--){
			now=PQ.top(); PQ.pop();
			printf("%d %s\n",now.t,item[now.p].name);
			PQ.push(UNIT(now.t+item[now.p].intv,now.p));
		}
	}
}
