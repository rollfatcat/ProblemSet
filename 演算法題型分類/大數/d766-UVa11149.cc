/* 給定Ｋ和Ｎ×Ｎ的二維矩陣，輸出Ａ+Ａ^2+Ａ^3+Ａ^4+Ａ^5...+Ａ^Ｋ＝？
 * 解題關鍵：快速幂次＋ D&C＝Ｏ(Ｎ^3 × ㏒Ｋ)
 * A＋A^2＋A^3＋A^4＋A^5...＋A^K，分奇數/偶數討論：
 * K is even, ＝( A＋A^2＋A^3＋...＋A^(K/2) )( I＋A^(K/2) )
 * K is odd , ＝( A＋A^2＋A^3＋...＋A^(K/2) )( I＋A^(K/2) )＋A^K
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=20;
const int MaxN=40;
const int MaxK=1e6;
const int M=10;

/* 矩陣需具備：複製、相乘、相加、加單位矩陣、輸出內容 */
struct MAT{
	int N, v[MaxN][MaxN];
	MAT(int N=0):N(N){}
	MAT(const MAT &rhs):N(rhs.N){ 
		for(int i=0;i<N;i++) 
			for(int j=0;j<N;j++)
				v[i][j]=rhs.v[i][j]; 
	}
	MAT Mul(const MAT &rhs){
		MAT out=MAT(N);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				out.v[i][j]=0;
				for(int k=0;k<N;k++)
					out.v[i][j]+=v[i][k]*rhs.v[k][j];
				out.v[i][j]%=M;
			}
		return out;
	}
	MAT Add(const MAT &rhs){
		MAT out=MAT(N);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				out.v[i][j]=v[i][j]+rhs.v[i][j];
				if(out.v[i][j]>=M) out.v[i][j]-=M;
			}
		return out;
	}
	MAT AdI(void){
		MAT out=MAT(*this);
		for(int i=0;i<N;i++)
			out.v[i][i]=(out.v[i][i]==9)? 0:out.v[i][i]+1;
		return out;
	}
	void Print(){
		for(int i=0;i<N;i++){
			printf("%d",v[i][0]);
			for(int j=1;j<N;j++)
				printf(" %d",v[i][j]);
			putchar('\n');
		}
	}
} matx[20], ans;

MAT FastMul(int K){
	MAT out=MAT(matx[0].N);
	/* 單位矩陣 */
    for(int i=0;i<out.N;i++)
		for(int j=0;j<out.N;j++)
			out.v[i][j]=i==j;
	for(int i=0;K>0;i++,K>>=1)
		if(K&1)
			out=out.Mul(matx[i]);
	return out;
}
MAT CDQ(int K){
	if(K==1) return matx[0];
	MAT out=FastMul(K>>1).AdI().Mul( CDQ(K>>1) );
	if(K&1) out=out.Add( FastMul(K) );
	return out;
}
int main(){
	
	int N, K, v;
	while(scanf("%d %d\n",&matx[0].N,&K) and matx[0].N>0){
		for(int i=0;i<matx[0].N;i++)
			for(int j=0;j<matx[0].N;j++)
				scanf("%d",&matx[0].v[i][j]),
				matx[0].v[i][j]%=M;
		for(int i=1;i<=__lg(K);i++)
			matx[i]=matx[i-1].Mul(matx[i-1]);
		ans=CDQ(K);
		ans.Print();
		putchar('\n');
	}
}