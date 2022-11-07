#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxA=1e9;

struct NODE{
	int t, v;
	NODE(int t=0,int v=0):t(t),v(v){}
	bool operator<(const NODE rhs)const{
		return t<rhs.t; }
} node[MaxN<<1];

int main(){
	int N, A, B;
	
	cin>>N;
	for(int i=0; i<N; i+=1){
		cin>>A>>B;
		node[ i ]=NODE( A , 1);
		node[i+N]=NODE(A+B,-1);
	}
	sort(node,node+(N<<1));
	// 累加
	for(int i=1;i<(N<<1);i+=1)
		if(node[i-1].t==node[i].t)
			node[i].v+=node[i-1].v;
	vector<int> ans(N+1);
	// 計算
	int now_c=0;
	for(int i=1;i<(N<<1);i+=1){
		if(node[i-1].t!=node[i].t){
			now_c+= node[i-1].v;
			ans[ now_c ]+=node[i].t-node[i-1].t;
		}
	}
	// output
	for(int i=1;i<=N;i+=1)
		cout<<ans[i]<<' ';
}