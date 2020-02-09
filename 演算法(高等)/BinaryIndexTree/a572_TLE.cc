// 題目要求『嚴格遞增』子序列(不一定連續)，動態規劃的遞增子序列問題
// 在動態規劃裡面的做法是 DP[i]=max( DP[j] )+num[i] ,if(j<i and num[i]>num[j])，O(n^2)
// 這題的時間需求要降低到O(n㏒n)，做法類似a596的BIT＋離散化
// BIT＋離散化:http://mypaper.pchome.com.tw/zerojudge/post/1323423828
/*
用的 binary indexed tree 去完成查詢。
先將測資離散化，之後調查 max(BIT[k]) 0<k<v[j]代表能接的最大值。
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10001;
int num[MAXN];
long DP[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(int N;scanInt(N);){
    memset(DP,0,sizeof(DP));
    long best=0, maxV;
    for(int i=0;i<N;i++){
      scanInt(num[i]);
      maxV=0;
      for(int j=0;j<i;j++)
        if(num[j]<num[i] and maxV<DP[j])
          maxV=DP[j];
      DP[i]=maxV+num[i];
      if(best<DP[i])
        best=DP[i];
    }
    printf("%ld\n",best);
  }
}
/*
6
14 14 9 11 1 19
5
16 9 10 13 17
*/