/* 滿足AX＋BY＝D，輸出min(|Ｘ|+|Ｙ|)且Ｘ≤Ｙ  
 * (X)直覺：暴力法找到一組解後再逐步調整
 * (X)轉換為背包問題 Ａ,B,D最大＝1e9
 * (v)數論：模擬『歐幾里德擴展定理』的過程。
 *    利用２x２的矩陣，初始化：[[1,0],[0,1]]
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNum=1e9;
int nA, nB, gcd;
int mat[2][2], now;
inline int ExGCD(int A,int B){
	int K=A/B, rhs=now^1;
	mat[now][0]-=K*mat[rhs][0];
	mat[now][1]-=K*mat[rhs][1];
	now=rhs;
	if(A%B==0) return B;
	return ExGCD(B,A%B);
}
int main(){
	for(int A, B;scanf("%d %d\n",&A,&B)!=EOF;){
		mat[0][0]=mat[1][1]=1;
		mat[0][1]=mat[1][0]=now=0;
		gcd=ExGCD(A,B);
		printf("%d %d %d\n",mat[now][0],mat[now][1],gcd);
	}
}