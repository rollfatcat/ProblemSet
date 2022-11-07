/* 給定Ｎ個點 adjancency_list，輸出Ｑ次查詢時指定起點和指定終點經過走Ｋ步的方法數？
 * 解題關鍵：動態規劃 - 快速乘方法 adjancency_list > adjancency_matrix
 * 題目的步數雖然不大( K ≤ 1e3 )，但是矩陣乘法的成本因為點數為 130，所以是 130*130*130
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=130;
const int MaxT=1e3;
const int MaxQ=2e4;
const int MOD=1e9+7;

int N, Q, K;
struct MAT{
	long v[130][130]={};
	MAT operator*(const MAT rhs)const{
		MAT ret;
		for(int r=0; r<N; r++)
			for(int c=0; c<N; c++){
				ret.v[r][c]=0;
				for(int k=0; k<N; k++)
					ret.v[r][c]+=v[r][k]*rhs.v[k][c]%MOD;
				ret.v[r][c]%=MOD;
			}
		return ret;
	}
} mat[10], ans;

int main(){
	int a, b;
	// setting
	scanf("%d",&N);
	for(a=0; a<N; a++){
		scanf("%d",&K);
		while( K-->0 ){
			scanf("%d",&b);
			mat[0].v[a][b-1]=1;
		}
	}
	for(int k=1; k<10; k++)
		mat[k]=mat[k-1]*mat[k-1];
	// 
	scanf("%d %d",&Q,&K);
	for(int n=0; n<N; n++)
		ans.v[n][n]=1;
	for(int m=0; 0<K and m<10; m++, K>>=1)
		if( K&1 )
			ans=ans*mat[m];
	while(Q-->0){
		scanf("%d %d",&a,&b);
		printf("%d\n",ans.v[a-1][b-1]);
	}
}