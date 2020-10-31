/* 給定Ｎ個食物的飽足感和Ｍ單位的飽足需求，最少需要多少個食物？
 * Ｎ ≦ 1e5，但每個食物的飽足感不超過 1e3。
 * 從最大飽足感的食物開始選。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxV=1e3;
int cnt[MaxV+1]={};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int N, K, v;
	cin>>N>>K;
	while(N-->0){
		cin>>v;
		cnt[v]++;
	}
	
	int ans=0;
	for(N=MaxV; N>0 and K-cnt[N]*N>0; N--)
		ans+=cnt[N],
		K-=cnt[N]*N;

	(N==0)? cout<<"OAQ\n" : cout<< ans+(K/N)+(K%N>0) <<'\n';
}