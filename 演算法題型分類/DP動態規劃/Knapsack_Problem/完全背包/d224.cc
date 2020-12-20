// 多元一次方程式(無限背包解)
#include<iostream>
using namespace std;
#define MaxN 1000001

int main(){
  int total;
  long long int cnt[MaxN];

  fill(cnt,cnt+MaxN,1);
  for(int i=2;i<MaxN;i++)
    cnt[i]+=cnt[i-2];
  for(int i=2;i<MaxN;i++)
    cnt[i]+=cnt[i-2];
  while(cin>>total)
    cout<<cnt[total]<<endl;
}