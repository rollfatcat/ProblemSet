// 卡塔藍數列的前(1<<20)項，但因為計算涉及取模且由N推導到(N+1)時有除法，等同計算乘法反元素

#include<iostream>
using namespace std;
#define MOD 1000000007

long DP[(1<<20)+1]={0,1,2,5};
void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void prinInt(long x){
  char ss[11];
  int len=0;
  for(; x; x/=10)
    ss[len++]=x%10+'0';
  while(len--)
    putchar(ss[len]);
  puts("");
}
long inverseN(long x){
  long maxtrix[2][2]={{1,0},{0,1}}, num[2]={x,MOD};
  bool now=0, nxt;
  for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
    nxt=now^1;  t=num[now]/num[nxt];
    maxtrix[now][0]-=t*maxtrix[nxt][0],
    maxtrix[now][1]-=t*maxtrix[nxt][1];
  }
  return (maxtrix[now][0]<0)?(maxtrix[now][0]+MOD):maxtrix[now][0];
}
int main(){
  for(int N=4; N<=(1<<20); N++)
    DP[N]=DP[N-1]*( (N<<2)-2 )%MOD, DP[N]=DP[N]*inverseN(N+1)%MOD;
  int T, N;
  for(scanInt(T);T--;)
    scanInt(N), prinInt(DP[N]);
}