// 中國餘式定理 => 乘法反元素
// 題目保證給的 p 是質數且數值範圍小於1e3，最多10個輸入 => LCM最多30位數 => __int128

#include<bits/stdc++.h>
using namespace std;

int Nrem[10];
int Nnum[10];

int InverseN(__int128 x,int mod){
  __int128 maxtrix[2][2]={{1,0},{0,1}};
  __int128 num[2]={x,mod};
  bool now=0, nxt;
  for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
    nxt=now^1;  t=num[now]/num[nxt];
    maxtrix[now][0]-=t*maxtrix[nxt][0],
    maxtrix[now][1]-=t*maxtrix[nxt][1];
  }
  if(maxtrix[now][0]<0)
    maxtrix[now][0]+=mod;
  return (int)maxtrix[now][0];
}
inline int readLine(int arr[],string ss,int N=0){
  arr[0]=N=0;
  for(int i=0;ss[i]!='\0';i++)
    if(ss[i]>='0') arr[N]=(arr[N]<<3)+(arr[N]<<1)+ss[i]-'0';
    else arr[++N]=0;
  return N+1;
}
inline void print(__int128 x){
  char ss[40];
  int L=0;
  for(;x;L++,x/=10)
    ss[L]=(x%10+'0');
  while(L--)
    cout<<ss[L];
  cout<<'\n';
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string ss;
  while(getline(cin,ss)){
    int maxp=0, N;
    N=readLine(Nnum,ss);
    getline(cin,ss);
    N=readLine(Nrem,ss);
    __int128 coLCM=1, sum=0, LCM;
    for(int i=0;i<N;i++)
      maxp=max(maxp,Nnum[i]),
      coLCM*=Nnum[i];
    for(int i=0;i<N;i++)
      LCM=coLCM/Nnum[i],
      sum+=InverseN(LCM,Nnum[i])*LCM*Nrem[i];
    sum%=coLCM;
    print( (sum>maxp)? sum: sum+coLCM );
  }
}
/*
997 991 983 977 971
967 953 947 941 937
*/