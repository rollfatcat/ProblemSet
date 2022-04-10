#include<bits/stdc++.h>
using namespace std;

const int MaxS=2e5;
int K;
string ss;
int prS[MaxS+1];

bool check(int Lm){
	// build prefix-sum
	prS[0]=0;
	for(int p=0; p<ss.length(); p++)
		prS[p+1]=prS[p]+(ss[p]=='.');
	// query
	for(int p=Lm; p<=ss.length(); p++)
		if( prS[p]-prS[p-Lm]<=K )
			return true;
	return false;
}
int main(){
	// input
	cin>>ss>>K;
	// Binary_Search
	int L=0;
	int R=ss.length();
	int ans;
	while(L<=R){
		int M=L+R>>1; // bit-operation
		if( check(M) ){
			ans=M;
			L=M+1;
		}else
			R=M-1;
	}
	cout<<ans;
}