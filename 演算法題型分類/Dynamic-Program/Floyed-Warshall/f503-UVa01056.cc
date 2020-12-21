/* 給定Ｒ段關係(每段關係包含兩個人名)，輸出整個網路圖當中『最遠的關係距離』？
 * 解題關繫：Floyed-Warshall
 * 題目線索：所有點對距離當中(All Pair Shortest Path)最遠的
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=50;
const int INF=INT_MAX;
int dp[MaxN][MaxN]={};
 
inline int GetID(string ss,unordered_map<string,int> &ID){
	if(ID.find(ss)==ID.end())
		ID[ss]=ID.size();
	return ID[ss];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int N, R;
	string ssu, ssv;
	for(int caseI=1; cin>>N>>R and N>0; caseI++){
		for(int u=0; u<N; u++)
			for(int v=u+1; v<N; v++)
				dp[u][v]=dp[v][u]=INF;
		unordered_map<string,int> ID;
		while(R-->0){
			cin>>ssu>>ssv;
			int u=GetID(ssu,ID);
			int v=GetID(ssv,ID);
			dp[u][v]=dp[v][u]=1;
		}
		for(int k=0; k<N; k++)
			for(int u=0; u<N; u++)
				for(int v=0; v<N; v++)
					if(dp[u][k]<INF and dp[k][v]<INF)
						dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
		int ans=0;
		for(int u=0; u<N; u++)
			for(int v=u+1; v<N; v++)
				ans=max(ans,dp[u][v]);
		cout<<"Network "<<caseI<<": ";
		(ans==INF)? cout<<"DISCONNECTED"<<'\n': cout<<ans<<'\n';
	}
}