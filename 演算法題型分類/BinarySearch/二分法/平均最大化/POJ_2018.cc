/* 給定Ｎ個數字和長度要求Ｆ，求連續區間和的長度不低於Ｆ時最大化平均值？
 * 解題關鍵：最大化平均值＝二分法
 * 猜測平均值＝每個數字都減掉猜測值，並設法讓連續區間和的值大於等於０
 * 長度不低於Ｆ的連續區間和轉換為前綴和後距離大於等於Ｆ的兩數相減 
 * ... 掃描線的概念：只需要維護小於等於 目前位置-F 的所有前綴和中最小的值
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
 
const int MaxN=1e5;
const int MaxV=2e3;
const double ESP=1e-5; // 題目要輸出乘以1000後的整數＝精確度為 1e-3 -> 計算過程要下修２位數
 
double num[MaxN|1];
double prS[MaxN|1];
 
bool check(double M,int& N,int& F){
	for(int i=1;i<=F;i++)
		prS[i]=num[i]-M+prS[i-1];
	double max_v=prS[F];
	double min_S=prS[0];
	for(int i=F+1;i<=N;i++){
		prS[i]=num[i]-M+prS[i-1];
		min_S=min(min_S,prS[i-F]);
		max_v=max(max_v,prS[i]-min_S);
	}
	return max_v>=ESP;
}
int main(){
 
	int N, F;
	scanf("%d %d\n%lf",&N,&F,&num[1]);
	/* 平均的猜測範圍必定落在極值內 */
    double L=num[1];
	double R=num[1];
	for(int i=2;i<=N;i++){
		scanf("%lf",&num[i]);
		L=min(L,num[i]);
		R=max(R,num[i]);
	}
    /* 這邊會牽涉到是否要進位的問題 */
	prS[0]=0.0;
	while(R-L>ESP){
		double M=(L+R)/2.0;
		(check(M,N,F))? L=M : R=M;
	}
	printf("%d\n",int(1000*R));
}