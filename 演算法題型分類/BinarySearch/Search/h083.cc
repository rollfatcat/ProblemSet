#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e4; 
const int MaxS=100;

vector<string> s[MaxS+1];
bool check(string &ss,int& K){
	for(int k=0; k<K; k+=1)
		if(ss[k]!=ss[ss.length()-K+k])
			return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;
	string ss;
	
	cin>>N;
	while(N-->0){
		cin>>ss;
		s[ss.length()].push_back(ss);
	}
	
	int t, ans=0;
	for(int R=1; R<=MaxS; R+=1){
		sort(s[R].begin(),s[R].end());
		for(int k=1; (k<<1)<R; k+=1){
			int L=R-(k<<1);
			for(string ss: s[R])
				if( check(ss,k) ){
					string pat=ss.substr(k,L);
					int t=lower_bound(s[L].begin(),s[L].end(),pat)-s[L].begin();
					ans+=(t<s[L].size() and s[L][t]==pat);
				}
		}
	}
	cout<<ans;
}
