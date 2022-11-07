#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=50;
const long MaxK=1e18;
const int MOD=1e9+7;
struct MAT{
	int N;
	long v[MaxN][MaxN];
	MAT operator*(const MAT rhs)const{
		MAT ret;
		ret.N=N;
		for(int r=0; r<N; r++)
			for(int c=0; c<N; c++){
				ret.v[r][c]=0;
				for(int k=0; k<N; k++)
					ret.v[r][c]=(ret.v[r][c]+v[r][k]*rhs.v[k][c])%MOD;
			}
		return ret;
	}
	vector<long> operator*(const vector<long> rhs)const{
		vector<long> ret(N);
		for(int c=0; c<N; c++){
			ret[c]=0;
			for(int k=0; k<N; k++)
				ret[c]=(ret[c]+v[c][k]*rhs[k])%MOD;
		}
		return ret;
	}
} mat[70];
 
int main(){
	long N, K;
 
	cin>>N>>K;
	mat[0].N=N;
	for(int r=0; r<N; r++)
		for(int c=0; c<N; c++)
			cin>>mat[0].v[r][c];
	// 預設從每個點當作起點時，方法數都是１
	vector<long> vec(N,1);
	// 快速冪次( Fast Binary Exponential )
	int p=0;
	do{
		if(K&1)
			vec=mat[p]*vec;
		mat[p+1]=mat[p]*mat[p];
		K>>=1;
		p+=1;
	}while(K>0);
	// output
	long ans=0;
	for(int n=0; n<N; n++)
		ans=(ans+vec[n])%MOD;
	cout<<ans;
}