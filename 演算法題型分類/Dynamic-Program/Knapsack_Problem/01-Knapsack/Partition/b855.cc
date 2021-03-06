// 問題為分堆問題(01背包的變形應用)，目標是使兩堆的差值最小化前提下輸出兩堆中數值較大者
#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int T, N, num[100];
  scanInt(T);
  while(T--){
    scanInt(N);
    int allS=0;
    for(int i=0;i<N;i++)
      scanInt(num[i]),
      allS+=num[i];
    int halfS=allS>>1;
    vector<int> DP(halfS+1,0);
    for(int i=0;i<N;i++)
      for(int j=halfS;j>=num[i];j--)
        DP[j]=max(DP[j],DP[j-num[i]]+num[i]);
    printf("%d\n",max(DP[halfS],allS-DP[halfS]));
  }
}