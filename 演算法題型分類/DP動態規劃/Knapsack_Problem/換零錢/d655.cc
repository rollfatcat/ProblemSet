/* 給定Ｑ筆測資，每次輸入Ｎ元，輸出使用到的最少貨幣個數？
 * 除了常見的面額{1,5,10,50,100,500,1000}，另外給定面額{30,70,110}
 * 解題關鍵：最大面額＝1000，代表狀態只需要記錄到1000以內，多出來的部分都可以先用 1000 消耗。
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=2e9;
const int MaxQ=1e6+1;
int DP[1000]={};

int main(){
	// 當面額＝{1,5,10,50,100,500}
  for(int sum=1;sum<1000;sum++)
    for(int num=sum; num>0; num/=10)
      DP[sum]+= (num%5)+ ((num%10)>=5);
  int new_token[3]={30,70,110};
  for(int i=0;i<3;i++)
    for(int j=new_token[i];j<1000;j++)
      DP[j]=min(DP[j],DP[j-new_token[i]]+1);
	
	int Q, N;
	scanf("%d\n",&Q);
	while(Q-->0)
		scanf("%d\n",&N),
		printf("%d\n",N/1000+DP[N%1000]);
	
}