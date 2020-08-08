/* 給定Ｎ個數字的數列，最少要用幾條不重疊的"嚴格遞增"數列才能覆蓋整條數列？
 * 解題核心： 
 * 將題目的要求：正向(由左而右)非嚴格遞減 LDS＝反向(由右而左)非嚴格遞增 LIS
 * Robinson-Schensted-Knuth Algorithm：Ｎ=1e5，時間需要壓縮到 N㏒N。
 * 透過 upper_bound() 找到的大於目標的數值 避免覆蓋到 相等於目標的數值
 */
#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e5;
int num[MaxN];
int vec[MaxN];

int main(){
	int N, vecL;
  while(scanf("%d\n",&N)!=EOF){
	  for(int i=0;i<N;i++)
	  	scanf("%d",&num[i]);
	  vec[0]=num[N-1], vecL=1;
	  for(int i=N-2;i>=0;i--)
	  	( num[i]>=vec[vecL-1] )? vec[vecL++]=num[i]: *upper_bound(vec,vec+vecL,num[i])=num[i];
	  printf("%d\n",vecL);
	}
}