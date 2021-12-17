// 莫隊算法
#include<bits/stdc++.h>
using namespace std;

const int MaxN=4e5;
const int MaxQ=4e5;

int pos[MaxN+1];
int org[MaxN+1];
int cnt[MaxN+1]={};
int qry[MaxQ][2];
int ord[MaxQ];
int ans[MaxQ];

bool compare(int a,int b){
	return pos[qry[a][0]] <pos[qry[b][0]] or
	       pos[qry[a][0]]==pos[qry[b][0]] and  
	       pos[qry[a][1]] <pos[qry[b][1]]; }

inline void add(int x,int& ret){
    ret+= cnt[x]==0;
    cnt[x]+=1;
}
inline void sub(int x,int& ret){
    cnt[x]-=1;
    ret-= cnt[x]==0;
}
int main(){
	int N, Q;
	
	scanf("%d",&N);
	for(int n=1; n<=N; n+=1)
		scanf("%d",&org[n]);
	scanf("%d",&Q);
	for(int q=0; q<Q; q+=1)
		scanf("%d %d",&qry[q][0],&qry[q][1]);
	
	int Bsz=ceil(sqrt(N));
	for(int n=0; n<N; n+=1)
		pos[n+1]=n/Bsz+1;
	iota(ord,ord+Q,0);
	sort(ord,ord+Q,compare);
	
	int nowL=0;
	int nowR=0;
	int ret=0;
    for(int o=0; o<Q; o+=1){
        while( nowR>qry[ ord[o] ][1] ) sub(org[nowR--],ret);
        while( nowR<qry[ ord[o] ][1] ) add(org[++nowR],ret);
        while( nowL>qry[ ord[o] ][0] ) add(org[--nowL],ret);
        while( nowL<qry[ ord[o] ][0] ) sub(org[nowL++],ret);
        ans[ ord[o] ]=ret;
    }
    for(int q=0; q<Q; q+=1)
        printf("%d\n",ans[q]);
}