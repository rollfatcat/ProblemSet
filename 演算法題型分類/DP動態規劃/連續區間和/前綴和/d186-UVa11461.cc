// 題目給定兩個端點：輸出區間內的平方個數
// 連續區間數量

#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 100001

int main(){
  int cnt[MaxN];
  memset(cnt,0,sizeof(cnt));
  for(int i=1;i*i<MaxN;i++)
    cnt[i*i]=1;
  for(int i=1;i<MaxN;i++)
    cnt[i]+=cnt[i-1];
  for(int a,b; cin>>a>>b and a; )
    cout<<cnt[b]-cnt[a-1]<<endl;
}
