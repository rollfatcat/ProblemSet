/* 給定Ｎ個票箱內２位後選人的選票，從中挑選Ｍ個，問最大化２位候選人的得票率(最簡分數表示)
 * 解題關鍵：得票率 = 平均值
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const double ESP=1e-6; 

int N, K;
int w[MaxN];
int v[MaxN];
int o[MaxN];
double t[MaxN];

bool compare(int lhs,int rhs){ return t[lhs]<t[rhs]; }
void show(int A,int B){
	if(A==0){ cout<<0<<'\n'; return; }
	if(A==B){ cout<<1<<'\n'; return; }
	int g=__gcd(A,B);
	cout<<(A/g)<<'/'<<(B/g)<<'\n';
}
bool judge(double nM,bool print){
	for(int n=0; n<N; n++)
		t[n]=v[n]-w[n]*nM;
	iota(o,o+N,0);
	sort(o,o+N,compare);
	double sum=0.0;
	int get=0;
	int all=0;
	for(int k=0; k<K; k++){
		sum+= t[o[k]];
		get+= v[o[k]];
		all+= w[o[k]];
	}
	if(print)
		show(all-get,all);
	return sum<0.0;
}
void solve(){
	double nL=0.0;
	double nR=1.0;
	double ans;
	while(nL+ESP<=nR){
		double nM=(nL+nR)/2.0;
		if( judge(nM,0) ){
			ans=nM;
			nR=nM-ESP;
		}else
			nL=nM+ESP;
	}
	judge(ans,1);
}
int main(){
	
	cin>>N>>K;
	for(int n=0; n<N; n++){
		cin>>v[n]>>w[n];
		v[n]+=w[n];
		swap(v[n],w[n]);
	}
	solve(); // maximize {X}
	for(int n=0; n<N; n++)
		v[n]=w[n]-v[n];
	solve(); // maximize {Ｙ}
}