// SegmentTree 版本
#include<iostream>
#include<cstring>
using namespace std;

int N, ST[300001], qR;
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int query(int l,int r,int idx){ // qL固定是1開始
  if(r<=qR) return ST[idx];
  int m=(l+r)>>1, lson=idx<<1, sum=query(l,m,lson);
  if(m<qR)  sum+=query(m+1,r,lson+1);
  return sum;
}
void OneNodeModify(int l,int r,int idx){
  ST[idx]++;
  if(l==r and l==qR) return;
  int m=(l+r)>>1, lson=idx<<1;
  if(m<qR) OneNodeModify(m+1,r,lson+1);
  else OneNodeModify(l,m,lson);
}
int main(){
  while(scanInt(N)){
    memset(ST,0,sizeof(ST));
    for(int x,all=1; all<=N; all++)
      scanInt(x), qR=x,
      printf("%d\n",all-query(1,N,1)),
      OneNodeModify(1,N,1);
  }
}