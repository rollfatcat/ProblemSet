// 填格子的方式找到質數, 88ms
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isP[20000000]={0};
int main(){
  // 填格子建表
  int Cprime[100000], len=0, bound=sqrt(20000000);
  for(int i=4;i<20000000;i+=2)  isP[i]=true;
  for(int i=9;i<20000000;i+=6)  isP[i]=true;
  for(int i=15;i<20000000;i+=10)  isP[i]=true;
  for(int i=7;i<=bound;i+=2)
    if(!isP[i]){
      for(int k=(i<<1), j=k+i; j<20000000; j+=k)
        isP[j]=true;
      if(!isP[i-4]) Cprime[len++]=i;
    }
  for(int i=bound+1;len<100000;i+=2)
    if(!isP[i] and !isP[i-4])
      Cprime[len++]=i;
  //
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for(int n; cin>>n;)
    n--, cout<<'('<<Cprime[n]-4<<", "<<Cprime[n]<< ')'<<endl;
}