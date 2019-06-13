// 觀察測資可以發現無法透過先形成盤面後檢查合法性才讓計數器加一的方式
// 推導方式類似狀態壓縮時判斷上下排之間合法方式的狀態轉移
// 遞迴推導：DP[i][j]＝DP[i-1][k] ( 0≤k<N and abs(j-k)>1)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 16

long DP[MAXN][MAXN];
inline int CharToInt(char c){ return (c<='9')?(c-'0'-1):(c-'A'+9); }
int main(){
  char ss[MAXN];
  while(scanf("%s",ss)!=EOF){
    memset(DP,0,sizeof(DP));
    int N=strlen(ss);
    // 初始化：First Row
    if(ss[0]=='?')
      for(int i=0;i<N;i++)
        DP[0][i]=1;
    else
      DP[0][CharToInt(ss[0])]=1;
    // 遞迴推導
    for(int i=1;i<N;i++){
      if(ss[i]=='?'){
        for(int now=0;now<N;now++)
          for(int j=0;j<N;j++)
            if( abs(j-now)>1 )
				      DP[i][now]+=DP[i-1][j];
      }
      else{ // 強迫這個Queen必須放到這個Column
        int now=CharToInt(ss[i]);
        for(int j=0;j<N;j++)
          if( abs(j-now)>1 )
				    DP[i][now]+=DP[i-1][j];
      }
    }
    long ans_sum=0;
    for(int j=0;j<N;j++)
      ans_sum+=DP[N-1][j];
    printf("%ld\n",ans_sum);
  }
}
/*
??????
???????????????
???8?????
43?????
*/