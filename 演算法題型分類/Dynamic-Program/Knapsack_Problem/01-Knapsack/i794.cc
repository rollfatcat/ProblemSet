/* 給定Ｎ個招式的損耗Ｄ和傷害輸出Ａ，損耗上限Ｗ和打倒敵人的最低輸出Ｅ，輸出保留下的剩餘魔力(必須大於０)？
 * 解題核心：01-knapsack problem ... 每個招式最多只能使用一次
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxW=1e4;
const int MaxE=1e6;
const int MaxN=1e4;

int dp[MaxW+1]={};
int main(){
	int W, E, N, D, A;
	
    cin>>W>>E>>N;
	// 01-knapsack problem
    for(int n=0; n<N; n++){
		cin>>D>>A;
		for(int d=W; D<=d; d--)
			dp[d]=max(dp[d],dp[d-D]+A);
	}
	for(D=W; 0<=D and E<=dp[D]; D--); D++;
	// output
    if(D>=W) cout<<"wryyyyyyyyyyyyy";
	else cout<<W-D;
}