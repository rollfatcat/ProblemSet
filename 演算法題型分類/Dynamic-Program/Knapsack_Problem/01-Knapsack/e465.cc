#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxM=1e5;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, M, S, v;
	int sum=0;
	
	cin>>M>>S>>N;
	bitset<MaxM+1> dp;
	dp[0]=1;
	for(int n=0; n<N; n++){
		cin>>v;
		sum+=v;
		dp= dp|(dp<<v);
	}
	for(S=max(0,S-(M-sum)); dp[S]==0; S++);
	cout<<S;
}