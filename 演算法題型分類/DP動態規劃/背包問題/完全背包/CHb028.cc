// 使用最少的零錢個數
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int v[6]={1,5,10,12,16,20};
  int cnt[101], W;
  fill(cnt,cnt+101,1000);
  cnt[0]=0;
  for(int i=0;i<6;i++)
    for(int j=v[i];j<=100;j++)
      cnt[j]=min(cnt[j], cnt[j-v[i]]+1);
  while(cin>>W)
    cout<<cnt[W]<<endl;
}