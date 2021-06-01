#include<bits/stdc++.h> 
using namespace std;
 
const int MaxN=2e5;
int main(){
	int N, v;
	scanf("%d",&N);
	
	map<int,int> memo[2];
	map<int,int>::iterator it; 
	
	for(int i=1; i<=N; i+=1){
		scanf("%d",&v);
		memo[0][v]=(memo[0].find(v-1)==memo[0].end())? 1:memo[0][v-1]+1;
	}
	int ansL=0;
	for(int i=1; i<=N; i+=1){
		scanf("%d",&v);
		memo[1][v]=(memo[1].find(v-1)==memo[1].end())? 1:memo[1][v-1]+1;
		ansL=max(ansL,min(memo[0][v],memo[1][v]));
	}
	printf("%d\n",ansL);
}