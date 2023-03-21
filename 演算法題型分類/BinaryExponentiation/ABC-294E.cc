/* 給定Ａ,Ｐ,Ｍ，問 sum(pow(x,i))%M, i=0,1,2...P
 * 盲點：轉換為等比公式時需要做除法，除法在取模時會轉為乘法反元素但是這必須符合前提：Ａ-1和Ｍ必須互質
 * 核心：透過矩陣乘法 和 快速冪次法計算
 *      矩陣 = [[A,1],[0,1]]*[0,1]，
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxA=1e9;
const int MaxM=1e9;
const long MaxP=1e12;

int A, M;
long P;
struct MAT{
	long v[2][2]={{0,1},{0,1}};
	vector<long> mul_vec(vector<long> vec){
		vector<long> ret(2);
		ret[0]=(v[0][0]*vec[0]+v[0][1]*vec[1])%M;
		ret[1]=(v[1][0]*vec[0]+v[1][1]*vec[1])%M;
		return ret;
	}
	MAT operator*(const MAT rhs)const{
		MAT ret;
	ret.v[0][0]=(v[0][0]*rhs.v[0][0]+v[0][1]*rhs.v[1][0])%M;
	ret.v[0][1]=(v[0][0]*rhs.v[0][1]+v[0][1]*rhs.v[1][1])%M;
	ret.v[1][0]=(v[1][0]*rhs.v[0][0]+v[1][1]*rhs.v[1][0])%M;
	ret.v[1][1]=(v[1][0]*rhs.v[0][1]+v[1][1]*rhs.v[1][1])%M;
		return ret;
	}
} now;

int main(){
	// input
	cin>>now.v[0][0]>>P>>M;
	// Fast Exponentiation
	vector<long> vec={0,1};
	for( ; 0<P; P>>=1){
		if( P&1 )
			vec=now.mul_vec(vec);
		now=now*now;
	}
	cout<<vec[0];
}