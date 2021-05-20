/* 給定Ｎ，輸出Ｎ的所有因數？
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=INT_MAX;
const int MaxSN=sqrt(MaxN);
bool notP[MaxSN+1]={};
vector<int> prime;
 
void Comb(int d,int n,vector<vector<int>>& fac, vector<int>& ans){
	if(d==fac.size()){ 
		ans.push_back(n); return; 
	}
	Comb(d+1,n,fac,ans);
	for(int i=1; i<=fac[d][1];i+=1)
		Comb(d+1,n*=fac[d][0],fac,ans);
}
int main(){
	// tabulation for prime
	for(int i=4;i<=MaxSN;i+=2)
		notP[i]=1;
	for(int i=3; i<=sqrt(MaxSN); i+=2)
		if(notP[i]==0)
			for(int j=i*i; j<MaxSN; j+=(i<<1))
				notP[j]=1;
	prime.push_back(2);
	for(int i=3; i<MaxSN; i+=2)
		if(notP[i]==0)
			prime.push_back(i);
	// query for N
	int N;
	while(scanf("%d",&N)!=EOF){
		vector< vector<int> > fac;
		for(int c,i=0; i<prime.size() and prime[i]*prime[i]<=N; i+=1){
			for(c=0; N%prime[i]==0; c++, N/=prime[i]);
			if(c>0) fac.push_back( {prime[i],c} );	
		}
		if(N>1) fac.push_back( {N,1} );
 
		vector<int> ans;
		Comb(0,1,fac,ans);
		sort(ans.begin(),ans.end());
		for(int x:ans)
			printf("%d ",x);
		putchar('\n');
	}
}