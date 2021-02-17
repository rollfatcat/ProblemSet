/* 自然數ｎ的皮薩諾週期( 記為π(n) )是指費氏數列模ｎ後的週期。
 * 問題的重點在於如何找到Ｍ'？
 * #t=7s
 * const int M=1e9+7;
 * int main(){
 * 	  int t=1;
 * 	  for(int a=1,b=1, c; a!=0 or b!=1; a=b,b=c,t++)
 * 		c=(a+b)%M;
 * 	  printf("%d\n",t);
 * }
 * 根據 Fibnocci 的 Homogeneous 性質：若存在循環時必定會接回第０項，也就是 0,1,1,...,0,1
 * Ｍ=1e9+7時，Ｍ'=2e9+16，得知Ｍ'後即可採用快速幂計算。
 */
#include<bits/stdc++.h>
using namespace std;

const int FM=1e9+7; 
const int SM=2e9+16;
const int MaxCaseT=1e5;// 1 ≤ｎ≤ 1e5
const long MaxX=1e15;  // 0 ≤ｘ≤ 1e15

long Fmat[50][2][2]={ {{1,1},{1,0}} };
long Smat[50][2][2]={ {{1,1},{1,0}} };

inline void MatrixMul(long A[2][2],long B[2][2],long C[2][2],const int &M){
	A[0][0]=(B[0][0]*C[0][0]+B[0][1]*C[1][0])%M,
	A[0][1]=(B[0][0]*C[0][1]+B[0][1]*C[1][1])%M,
	A[1][0]=(B[1][0]*C[0][0]+B[1][1]*C[1][0])%M,
	A[1][1]=(B[1][0]*C[0][1]+B[1][1]*C[1][1])%M;
}
inline long FuncIn(long x){
	bool pre=0, now=1;
	long mat[2][2][2]={ {{1,0},{0,1}} };
	for(int i=0;x>0;x>>=1,i++)
		if(x&1){
			MatrixMul(mat[now],mat[pre],Smat[i],SM);
			swap(pre,now);
		}
	return mat[pre][1][0];
}
inline long FuncOut(long x){
	bool pre=0, now=1;
	long mat[2][2][2]={ {{1,0},{0,1}} };
	for(int i=0;x>0;x>>=1,i++)
		if(x&1){
			MatrixMul(mat[now],mat[pre],Fmat[i],FM);
			swap(pre,now);
		}
	return mat[pre][1][0];
}
int main(){
	int caseT;
	long x;
	
	for(int now=1; now<=49; now++)
		MatrixMul(Fmat[now],Fmat[now-1],Fmat[now-1],FM),
		MatrixMul(Smat[now],Smat[now-1],Smat[now-1],SM);
	
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%ld\n",&x);
		printf("%ld\n",FuncOut( FuncIn(x) ));
	}
}