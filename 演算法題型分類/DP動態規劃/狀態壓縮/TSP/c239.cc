// TSP：旅行銷售員 => 動態規劃解法
// TSP(TopDown)：http://mypaper.pchome.com.tw/zerojudge/post/1323281846 - from Morris
// 作法參考：https://blog.csdn.net/qq_39322743/article/details/79700051?utm_source=blogxgwz0
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define MaxN 15
#define INF 0x7fffffff

int n, N, map[MaxN][MaxN];
int minDP[MaxN][1<<MaxN-1];
int maxDP[MaxN][1<<MaxN-1];
int GCD(int a,int b){ return(a%b)?GCD(b,a%b):b; }
int main(){

  while(cin>>n){
    int MaxS=(1<<n-1)-1;
    memset(map,0x7f,sizeof(map));
    memset(minDP,0x7f,sizeof(minDP));
    memset(maxDP,0,sizeof(maxDP));
    // ---BottomUp---
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        cin>>map[i][j], map[j][i]=map[i][j];
    minDP[0][0]=0,  maxDP[0][0]=INF;
    for(int i=1; i<n; i++)
      maxDP[i][0]=minDP[i][0]=map[i][0];
    for(int nowS=1; nowS<MaxS; nowS++)
      for(int i=1;i<n;i++) //i不在集合中
        if( !(nowS&(1<<i-1)) )
          for(int j=1;j<n;j++) //j在集合中
            if( nowS&(1<<j-1) )
              minDP[i][nowS]=min(minDP[i][nowS],minDP[j][nowS^(1<<j-1)]+map[i][j]),
              maxDP[i][nowS]=max(maxDP[i][nowS],maxDP[j][nowS^(1<<j-1)]+map[i][j]);

    minDP[0][MaxS]=INF, maxDP[0][MaxS]=0;
    for(int i=1;i<n;i++)
      minDP[0][MaxS]=min(minDP[0][MaxS],map[0][i]+minDP[i][MaxS^(1<<i-1)]),
      maxDP[0][MaxS]=max(maxDP[0][MaxS],map[0][i]+maxDP[i][MaxS^(1<<i-1)]);

    // ---輸出調整(約分後分母為1時只要輸出分子)---
    int gcd=GCD(maxDP[0][MaxS],minDP[0][MaxS]);
    if(minDP[0][MaxS]==gcd) cout<<(maxDP[0][MaxS]/gcd)<<endl;
    else cout<<(maxDP[0][MaxS]/gcd)<<'/'<<(minDP[0][MaxS]/gcd)<<endl;
  }
}
/*
4
1 2 3
6 2
3
*/