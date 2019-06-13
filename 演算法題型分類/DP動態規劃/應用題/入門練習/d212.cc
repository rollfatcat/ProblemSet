// 經典爬樓梯問題＋大數處理
#include<iostream>
#include<limits>
using namespace std;

int main(){
  // unsigned long long int 上限：18446744073709551615 = 1e19
  // cout<<numeric_limits<unsigned long long int>::max()<<endl;

  long long int Fib[100];
  long long int BigFib[10][2];
  Fib[0]=Fib[1]=1;
  for(int i=2;i<=91;i++)
    Fib[i]=Fib[i-1]+Fib[i-2];

  BigFib[0][0]=Fib[90]%(1000000000000000000);
  BigFib[0][1]=Fib[90]/(1000000000000000000);
  BigFib[1][0]=Fib[91]%(1000000000000000000);
  BigFib[1][1]=Fib[91]/(1000000000000000000);
  // 大數計算
  for(int i=2;i<=9;i++)
    BigFib[i][0]=BigFib[i-1][0]+BigFib[i-2][0],
    BigFib[i][1]=BigFib[i-1][1]+BigFib[i-2][1]+BigFib[i][0]/(1000000000000000000),
    BigFib[i][0]=BigFib[i][0]%(1000000000000000000);

  int n;
  while(scanf("%d",&n)!=EOF)
    if(n<=91)
      printf("%lld\n",Fib[n]);
    else
      n-=90,  printf("%lld%018lld\n",BigFib[n][1],BigFib[n][0]);
}