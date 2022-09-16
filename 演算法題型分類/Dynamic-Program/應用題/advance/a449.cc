// DP解：http://mypaper.pchome.com.tw/zerojudge/post/1323263185
/* DP[i] 表示可以裝 i 隻烏龜的情況, 那麼 DP[i].c代表裝 i 隻需要幾輛公車, DP[i].w代表此時的公車負重,
 * 那麼我們可以知道 DP[i].c越小越好, DP[i].w越小越好
 */
#include<iostream>
using namespace std;

struct nn{
  int c, w;
  bool operator>(const nn other)const{ return(c==other.c)?(w>other.w):(c>other.c); }
}DP[2001], pre;
void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9'; x=(x<<3)+(x<<1)+c-'0');}
int main(){

  int n, k, m, w, i, j;
  scanInt(n), scanInt(k), scanInt(m);

  DP[0].c=1, DP[0].w=0;
  for(i=1; i<=n; i++)
    DP[i].c=n+1, DP[i].w=m+1;
  for(i=1; i<=n; i++){
    scanInt(w);
    if(w>m) continue;
    for(j=i-1; j>=0; j--){ // 反向更新
      pre=DP[j], pre.w+=w;
      if( pre.w>m ){
        pre.c+=1, pre.w=w;
        if( pre.c<=k and DP[j+1]>pre )
          DP[j+1]=pre;
      } else {
        if( DP[j+1]>pre )
          DP[j+1]=pre;
      }
    }
  }
  for(i=n; i>=0 and DP[i].c==n+1; i--);
  printf("%d\n",i);
}