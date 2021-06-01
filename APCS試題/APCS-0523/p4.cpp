#include<bits/stdc++.h> 
using namespace std;
 
const int MaxN=1e5;
const int MaxV=1e8;
int main(){
	int N, M, X, K, v;
	scanf("%d %d %d %d",&N,&M,&X,&K);
	
	priority_queue<int> memo[2];
	long preS=0;
	for(int i=0; i<N+M; i+=1){
		scanf("%d",&v);
		memo[0].push(v);
		if( memo[0].size()>=K ){
			preS+= memo[0].top();
			memo[1].push( memo[0].top() );
			memo[0].pop();
		}
		if( memo[1].size()>X ){
			preS-= memo[1].top();
			memo[1].pop();
		}
		if(i>=N-1)
			printf("%ld\n",preS);
	}
}