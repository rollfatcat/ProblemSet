#include<iostream>
using namespace std;
#define MaxN 10001

int num[MaxN]={};
int sum[MaxN]={};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int maxNum;
  for(int N, M; cin>>N>>M; ){
    sum[0]=0;
    for(int i=1;i<=N;i++)
      cin>>num[i],
      sum[i]=sum[i-1]+num[i];

    maxNum=0;
    for(int ed=M;ed<=N;ed++)
      if(maxNum<sum[ed]-sum[ed-M])
        maxNum=sum[ed]-sum[ed-M];
    for(int st=1;st<M;st++)
      if(maxNum<sum[N]-sum[N-M+st]+sum[st])
        maxNum=sum[N]-sum[N-M+st]+sum[st];
    cout<<maxNum<<endl;
  }
}