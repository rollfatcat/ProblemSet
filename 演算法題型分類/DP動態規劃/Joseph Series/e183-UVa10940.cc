// 考量Ｎ≤5e5，以下題解採用『動態規劃法』且考量到Ｎ的遞增關係需要前處理
// 注意：這題不能每一次詢問才用動態規劃解法跑一次
// 觀察Ｎ的關係可以發現Ｎ=4時前3步的計算已經在Ｎ=3時算過所以直接在存取DP值即可

#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005

int DP[MAXN]={0,1,2};
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return true;}
int main(){
  int N=500000, who=0;
  for(int t=2;t<N;t++)
    who=(who+2)%t,
    DP[t+1]=who+2;
  while(scanInt(N) and N)
    printf("%d\n",DP[N]);
}