// DP的 Longest Increasing Sequence(LIS)+Longest Decreasing Sequence(LDS)
// 題目保證數字不重複(不需考慮嚴格遞增或是嚴格遞減)
/* 假設 ith 量為第一輛留下來的車 L=LIS[i]+LDS[i]-1，
 * 逆序DP，把最後一個數當作起點，如果求LIS則DP[i]就是從a[n]--->a[i]的LIS，也是a[i]--->a[n]的LDS。
 * 原文：https://blog.csdn.net/L_BestCoder/article/details/64131002
 * 以下的方法是O(N^2)作法完成後可以接『高階演算法』的 a596 題目必須是O(N㏒N)
 */
#include<bits/stdc++.h>
using namespace std;
const int MaxN=2e3;
int num[MaxN];
int LIS[MaxN];
int LDS[MaxN];

int main(){
	int Q, N;
  scanf("%d\n",&Q);
  while(Q-->0){
  	scanf("%d\n",&N);
  	for(int i=0;i<N;i++)
  		scanf("%d",&num[i]);
  	int maxL=0;
  	for(int i=N-1;i>=0;i--){
  		LIS[i]=LDS[i]=0;
  		for(int j=i+1;j<N;j++){
  			if(num[i]<num[j])
  				LIS[i]=max(LIS[i],LIS[j]);
  			if(num[i]>num[j])
  				LDS[i]=max(LDS[i],LDS[j]);
  		}
  		LIS[i]++;
  		LDS[i]++;
  		maxL=max(maxL,LIS[i]+LDS[i]-1);
  	}
  	printf("%d\n",maxL);
  }
}