/* 給定Ｎ個數字和長度要求Ｆ，求連續區間和的長度不低於Ｆ時最大化平均值？
 * 解題關鍵：最大化平均值＝二分法
 * 猜測平均值＝每個數字都減掉猜測值，檢驗：prefix_sum[E] - prefix_sum[S] ≥ ０, if E-S ≥ F
 * 貪婪法：枚舉每個Ｅ，保留和Ｅ距離大於等於Ｆ時的最小前綴和
 * 題目盲區：精確度 ... 答案要輸出乘以1e3的"整數" ... 用 double 求最大平均值後放大 1e3 倍會有誤差
 */
#include<stdio.h>
#include<algorithm>
using namespace std;
#define ll long long

const int MaxN=1e5;
const int MaxV=2e3;
int N, F;
int num[MaxN+1];
ll  prS[MaxN+1]={};

bool check(int M){
	for(int n=1; n<F; n++)
		prS[n]=num[n]-M+prS[n-1];
	ll min_S=0;
	for(int n=F; n<=N; n++){
		prS[n]=num[n]-M+prS[n-1];
		min_S=min(min_S,prS[n-F]);
		if(prS[n]-min_S>=0)
			return true;
	}
	return false;
}

int main(){
	scanf("%d %d",&N,&F);
	int L=2e6; // 題目保證單一格最大的牛隻數量是 2e3
	int R=1;
	for(int n=1; n<=N; n++){
		scanf("%d",&num[n]); 
		num[n]*=1000; // 題目的精確度要求小數點後３位的整數，所以放大 1e3 倍做整數計算
		L=min(L,num[n]);
		R=max(R,num[n]);
	}
	int ans;
	while(L<=R){
		int M=L+R>>1;
		if(check(M)){
			L=M+1; 
			ans=M;
		}else
			R=M-1;
	}
	printf("%d",ans);
}