// 題目等同 b229-TOI2009 DP解
#include<iostream>
using namespace std;
#define MaxN 10001

int main(){
  int GoUp[MaxN], Side[MaxN], base=12345;
  GoUp[1]=3,  Side[1]=2;
  for(int i=2;i<MaxN;i++)
    Side[i]=(GoUp[i-1]+Side[i-1])%base,
    GoUp[i]=(Side[i]+Side[i-1])%base;
  for(int n; cin>>n; )
    cout<<GoUp[n]<<endl;
}