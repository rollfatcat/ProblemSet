// 建質數表偷跑+ 計算連續區段內的總合

#include<iostream>
#include<cmath>
using namespace std;
#define MaxNum 7002

bool isPrime[MaxNum];
int sum[MaxNum];
int main(void){
  // Build Table
  fill(isPrime,isPrime+MaxNum,true);
  isPrime[1]=false;
  for(int i=2;i<=sqrt(MaxNum);i++)
    if(isPrime[i])
      for(int j=2;j<=MaxNum/i;j++)
        isPrime[ i*j ]=false;
  fill(sum,sum+MaxNum,0);
  for(int i=1;i<MaxNum;i++)
    sum[i]=sum[i-1]+( (isPrime[i])?0:i );
  //
  int T, a, b;
  cin>>T;
  while(T--)
    cin>>a>>b, cout<<sum[b]-sum[a-1]<<endl;
}