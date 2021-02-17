// 快速乘方法＋大數乘法
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int a[2][1000], alen[2];
  int b[2][1000], blen[2];
  int n;

  cin>>a[0][0]>>n;
  alen[0]=1,
  blen[0]=b[0][0]=1,
  blen[1]=0;

  bool now=0, nxt=1, bnow=0, bnxt=1;
  for( ; n>0 ; n/=2, now=nxt, nxt^=1){
    // 決定要不要乘底數
    if(n%2){
      blen[bnxt]=blen[bnow]+alen[now];
      for(int i=0;i<blen[bnxt];i++)
        b[bnxt][i]=0;
      for(int i=0;i<blen[bnow];i++)
        for(int j=0;j<alen[now];j++)
          b[bnxt][i+j]+=b[bnow][i]*a[now][j];
      for(int i=0, carry=0;i<blen[bnxt];i++)
        b[bnxt][i]+=carry, carry=b[bnxt][i]/10, b[bnxt][i]%=10;
      for(blen[bnxt]--; b[bnxt][blen[bnxt]]==0;blen[bnxt]--);
      blen[bnxt]++;
      bnow=bnxt,  bnxt^=1;
    }
    // 把底數做平方
    alen[nxt]=alen[now]<<1;
    for(int i=0;i<alen[nxt];i++)
      a[nxt][i]=0;
    for(int i=0;i<alen[now];i++)
      for(int j=0;j<alen[now];j++)
        a[nxt][i+j]+=a[now][i]*a[now][j];
    for(int i=0, carry=0;i<alen[nxt];i++)
      a[nxt][i]+=carry, carry=a[nxt][i]/10, a[nxt][i]%=10;
    for(alen[nxt]--; a[nxt][alen[nxt]]==0;alen[nxt]--);
    alen[nxt]++;
  }
  //
  for(int i=blen[bnow]-1;i>=0;i--)
    printf("%d",b[bnow][i]);
  printf("\n");
}
