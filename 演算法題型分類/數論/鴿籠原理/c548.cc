// 數論(鴿籠原理): 2 ≦ K ≦ N
/* 令 Si 為前 i 個數字之和，能定義出 S0∼Sn 這 n+1 個前綴。依據鴿籠原理，在模 K ≤ N 時至少有兩前綴同餘。
 * 而 Sa≡Sb(mod k)(a<b) 自然代表 (a,b] 是一組解了。整體能在線性時間下解決。
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, K, nowv, idx;
  int memo[100001];
  int IsIn[100001];

  memset(IsIn,0xff,sizeof(IsIn));
  IsIn[0]=0;

  scanInt(N),
  scanInt(K);
  for(idx=1;idx<=N;idx++){
    scanInt(nowv),
    nowv=(memo[idx-1]+nowv%K)%K;
    if(IsIn[ nowv ]==-1)
      memo[idx]=nowv,
      IsIn[nowv]=idx;
    else{
      printf("%d\n",idx-IsIn[nowv]);
      for(int i=IsIn[nowv]+1;i<=idx;i++)
        printf("%d ",i);
      puts("");
      break;
    }
  }
  for(idx++;idx<=N;idx++)
    scanInt(nowv);
}
// 7 92 47 5 1
// 1  2  1