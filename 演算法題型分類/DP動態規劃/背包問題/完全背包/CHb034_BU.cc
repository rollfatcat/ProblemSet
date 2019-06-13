// 使用最少的零錢個數
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int v[9]={1,5,10,50,100,500,1000,5000,10000};
  int cnt[100001], W;
  fill(cnt,cnt+100001,100000);
  cnt[0]=0;
  for(int i=0;i<9;i++)
    for(int j=v[i];j<=100000;j++)
      cnt[j]=min(cnt[j], cnt[j-v[i]]+1);
  while(cin>>W)
    cout<<cnt[W]<<endl;
}