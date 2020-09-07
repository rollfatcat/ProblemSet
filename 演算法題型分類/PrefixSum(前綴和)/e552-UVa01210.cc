#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
	// seive : 找出 1e4 以內的質數
	vector<bool> NotP(MaxN);
	for(int i=0;i<25;i++)
		for(int j=3; prime[i]*j<MaxN; j+=2)
			NotP[ prime[i]*j ]=1;
	for(int i=101;i<MaxN;i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	// 一邊計算前綴和時, 同時計算和前面每一個數字的差值(連續區間和)
	vector<int> cnt(MaxN+1);
	vector<int> PreSum(1);
	for(int i=0;i<prime.size();i++){
		PreSum.push_back( PreSum.back()+prime[i] );
		for(int j=i;j>=0 and PreSum[i+1]-PreSum[j]<=MaxN;j--)
			cnt[ PreSum[i+1]-PreSum[j] ]++;
	}
	//
	for(int N; scanf("%d",&N) and N;)
		printf("%d\n",cnt[N]);
}