/* 小智有Ｘ張牌而且小遙有Ｙ張牌，小智作弊新增某張牌時在可以「提昇勝率」的前提下點數最少是多少？
 * 新增牌的點數必須是小智牌堆中存在的
 * 提升勝率的定義 : l( #該張牌輸給小遙牌堆 ) ≤ w ( #該張牌贏過小遙牌堆 )且 W+w > L+l
 */ 
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxM=1e5;
int x[MaxN];
int y[MaxM];

long func(int a[],int b[],int Acnt,int Bcnt,long ret=0){
	for(int pb=0, pa=0; pa<Acnt; pa++){
		while(pb<Bcnt and b[pb]<a[pa])
			pb++;
		ret+=pb;	
	}
	return ret;
}
int main(){
	int N, M, n, m, w, l;
	
	cin>>N>>M;
	for(n=0; n<N; n++)
		cin>>x[n];
	for(m=0; m<M; m++)
		cin>>y[m];
	
	sort(x,x+N);
	sort(y,y+M);
	long W=func(x,y,N,M);
	long L=func(y,x,M,N);
	for(w=n=0; n<N; n++){
		for(   ; w<M and  y[w]<x[n]; w++);
		for(l=w; l<M and y[l]<=x[n]; l++);
		if( w>=M-l and W+w>L+M-l ){
			cout<<x[n];
			return 0;
		}
	}
	cout<<-1;
}