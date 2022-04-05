#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxA=1e9;

int node[MaxN][2];// 原始資料

int ord[MaxN<<1];
int cnt[MaxN<<1]={};
int main(){
	int N, A, B;
	
	cin>>N;
	for(int i=0; i<N; i+=1){
		cin>>node[i][0]>>node[i][1];
		node[i][1]+=node[i][0];
		ord[ i ]=node[i][0];
		ord[i+N]=node[i][1];
	}
	// 離散化
	sort(ord,ord+(N<<1));
	int uN=unique(ord,ord+(N<<1))-ord;
	// 將原始的時間點對應到"排名" 
	for(int i=0; i<N; i+=1){
		cnt[ lower_bound(ord,ord+uN,node[i][0])-ord ]+=1;
		cnt[ lower_bound(ord,ord+uN,node[i][1])-ord ]-=1;
	}
	//
	vector<int> ans(N+1);
	int now_c=cnt[0];
	for(int i=1; i<uN; i+=1){
		ans[now_c]+= ord[i]-ord[i-1];
		now_c+=cnt[i];
	}
	for(int i=1; i<=N; i+=1)
		cout<<ans[i]<<' ';
}