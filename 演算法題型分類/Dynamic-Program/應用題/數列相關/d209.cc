// 作法請參考：b593，這題只是將 domain 擴大但核心想法不變，('a','z')->(0,2999)
#include<bits/stdc++.h>
using namespace std;

const int MOD=10000000;
const int MAXL=3000;
int DP[MAXL+1][MAXL+1]={}; // DP[A][B]=Ｃ(A+B)取B
int main(){
  // init : 解法是依照『斜率』去填格子，我自己是由上到下左到右填
  for(int i=0;i<=MAXL;i++)
    DP[0][i]=DP[i][0]=1;
  for(int i=1;i<=MAXL;i++)
    for(int j=1;j<=MAXL-i;j++)
      DP[i][j]=(DP[i-1][j]+DP[i][j-1])%MOD;
  // Main Function
  int idx, buff_len;
  int buff[1002];
  while(scanf("%d",&buff_len)!=EOF){
    for(idx=0;idx<buff_len;idx++)
      scanf("%d",&buff[idx]);
    int number=0;
    for(idx=1;idx<buff_len;idx++)
      number=(number+DP[MAXL-idx][idx])%MOD;
    int last=0;
    for(idx=0;idx<buff_len;idx++,last++)
      for(;last<buff[idx];last++)
        number=( number+DP[MAXL-last-(buff_len-idx)][buff_len-1-idx] )%MOD;
    printf("%07d\n",number+1);
  }
}