// 題目保證只有+和x 且計算的數字可用int紀錄
// 實作不用Stack但需要有對應的概念
#include<iostream>
#include<cstring>
using namespace std;
#define mod 10000

int main(){
  char c;
  int sum=0, num, mul=1;
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while(scanf("%c",&c)!=EOF){
    if(isdigit(c))  num=(10*num+c-'0')%mod;
    else if(c=='+') sum=(sum+(mul*num)%mod)%mod, num=0, mul=1;
    else if(c=='*') mul=(mul*num)%mod, num=0;
    else break;
  }
  if(num>0) sum=(sum+(mul*num)%mod)%mod;
  cout<<sum<<endl;
}