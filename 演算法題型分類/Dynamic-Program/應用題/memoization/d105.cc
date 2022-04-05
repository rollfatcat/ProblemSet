// 直接Bottom-Up 推展到m次即可, 注意環狀的順序
// 可以說明LinkList的概念
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 31

int main(){
  int n, m;
  int cnt[MaxN][MaxN];
  int pre[MaxN], nxt[MaxN];
  while(cin>>n>>m){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)
      pre[i]=i-1, nxt[i]=i+1;
    pre[0]=n-1, nxt[n-1]=0;

    cnt[0][0]=1;
    for(int t=1;t<=m;t++)
      for(int i=0;i<n;i++)
        cnt[t][i]=cnt[t-1][ pre[i] ]+cnt[t-1][ nxt[i] ];
    cout<<cnt[m][0]<<endl;
  }
}