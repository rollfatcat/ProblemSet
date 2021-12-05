/*
 */ 
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e2;
int need[MaxN];
vector<int> to[MaxN];

int main(){
	int caseT, N, M, A, B;
	
  while(scanf("%d %d",&N,&M)!=EOF){
  	fill(need,need+N+1,0);
  	for(int n=0; n<N; n+=1)
  		to[n].clear();
  	while(M-->0){
			scanf("%d %d",&A,&B);
			to[A].push_back(B);
			need[B]+=1;
  	}
  	//
  	priority_queue<int> PQ;
  	for(int n=0; n<N; n+=1)
  		if(need[n]==0)
  			PQ.push(-n);
  	// 
  	while(PQ.empty()==0){
  		int now=-PQ.top(); PQ.pop();
  		printf("%d ",now);
  		for(int rhs: to[now]){
  			need[rhs]-=1;
  			if(need[rhs]==0)
  				PQ.push(-rhs);
  		}
  	}
		putchar('\n');
  }
}