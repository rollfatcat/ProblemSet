// 此題有規則解(0ms)，可以和c519一起看，但也可以用簡單模擬(0.6s)
/* 規則寫得很複雜...，但概括就是往左上移動，超過邊界就overflow
 * 直到這一整個斜條都被填滿往下一斜條填
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=5000;
bool use[MAXN][MAXN];
int N, tR, tC;

int main(){
  int T, num;
  for(scanf("%d",&T);T--;){
    scanf("%d %d %d",&N,&tR,&tC), tR--, tC--;
    memset(use,0,sizeof(use));
    use[0][N>>1]=1;
    int now_x=0, now_y=N>>1, nxt_x, nxt_y;
    for(num=1; !use[tR][tC]; now_x=nxt_x,now_y=nxt_y){
      num++;
      nxt_x=(now_x)?(now_x-1):(N-1),
      nxt_y=(now_y)?(now_y-1):(N-1);
      if(use[nxt_x][nxt_y])
        nxt_x=(now_x==N-1)?0:(now_x+1),
        nxt_y=now_y;
      use[nxt_x][nxt_y]=1;
    }
    printf("%d\n",num);
  }
}