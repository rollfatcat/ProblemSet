/* 題目給Ｎ個人的身高，每次查詢時給定Ｋ，某兩人的身高剛好差Ｋ的情況是否存在？
 * 解題關鍵：TwoPointer
 * (X) 排序後枚舉兩個數字產生所有的差值，數字有1e5個所以差值最多有5e9個(太多不可能記錄起來)
 * (O) 線性枚舉利用 slide window 移動計算差值是否剛好是查詢的目標
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxQ=1e3;
const int MaxA=INT_MAX;
int hgt[MaxN];
int main(){
	int N, Q, qv;
  scanf("%d %d\n",&N,&Q);
  for(int i=0;i<N;i++)
  	scanf("%d",&hgt[i]);
  sort(hgt,hgt+N);
  while(Q-->0){
  	scanf("%d",&qv);
  	int front=0, back, nowD;
  	for(back=1;back<N;back++){
  		nowD=hgt[back]-hgt[front];
  		while(front<=back and nowD>qv)
  			nowD=hgt[back]-hgt[++front];
  		if(nowD==qv)
  			break;
  	}
  	puts( (back<N)?"YES":"NO" );
  }
}