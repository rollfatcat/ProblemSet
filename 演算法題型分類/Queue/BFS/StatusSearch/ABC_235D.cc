#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxA=1e6;

int memo[MaxN+1];
int ZeroNum(int x,int v=1){
	for(; x>9; x/=10)
		v*=10;
	return v;
}
int main(){
	int A, N;
	long now, nxt;
	
	scanf("%d %d",&A,&N);
	// BFS
	fill(memo,memo+1+MaxN,-1);
	deque<int> Q={1};
	memo[1]=0;
	while(Q.empty()==0){
		now=Q.front(); Q.pop_front();
		nxt=now*A;
		if(nxt<=MaxN and memo[nxt]==-1){
			memo[nxt]=memo[now]+1;
			Q.push_back(nxt);
		}
		if(now<10 or (now%10)==0) continue;
		nxt=now%10*ZeroNum(now)+(now/10);
		if(memo[nxt]==-1){
			memo[nxt]=memo[now]+1;
			Q.push_back(nxt);
		}
	}
	printf("%d",memo[N]);
}