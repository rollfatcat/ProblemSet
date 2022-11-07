#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxP=1e7;

struct NODE{
	int p, v;
	NODE(int p=0,int v=0):p(p),v(v){}
} node[MaxN<<1];
int srt[MaxN<<1]; // 曾經出現過的時間點
int cnt[MaxN<<1]={};

int main(){
	int N, s, e;
	
	cin>>N;
	// 差分：拆解成２個變化量的時間點
	for(int i=0; i<N; i+=1){
		cin>>s>>e;
		node[ i ]=NODE( s, 1);
		node[i+N]=NODE( e,-1);
		 srt[ i ]=s;
		 srt[i+N]=e;
	}
	// 掃描線：時間由小到大
	sort(srt,srt+(2*N));
	//
	for(int i=0; i<(2*N); i+=1){
		int p=lower_bound(srt,srt+2*N,node[i].p)-srt;
		cnt[p]+=node[i].v;
	}
	// 掃描線
	int now_c=0;
	int pre_s=0;
	int ansL=0;
	for(int i=0; i<(2*N); i+=1){
		if(now_c==0) pre_s=srt[i];
		now_c+=cnt[i];
		if(now_c==0) ansL+=srt[i]-pre_s;
	}
	cout<<ansL<<'\n';
}