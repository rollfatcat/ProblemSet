// 1D SegmentTree，單點修改+區間詢問
#include<cstdio>
using namespace std;
#define MaxN 200001

int N, Q, Ql, Qr;
bool on[MaxN<<2]={};
void scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); }
void Update(int l,int r,int idx){
  if(l==r){ on[idx]^=true; return; }
  int m=(l+r)>>1, Lson=idx<<1;
  if(Qr<=m) Update(l,m,Lson);
  else  Update(m+1,r,Lson+1);
  on[idx]^=true;
}
bool Query(int l,int r,int idx){
  if(Ql<=l and r<=Qr) return on[idx];
  int m=(l+r)>>1, Lson=idx<<1;
  if(Qr<=m) return Query(l,m,Lson);
  else if(Ql>m) return Query(m+1,r,Lson+1);
  else  return Query(l,m,Lson)^Query(m+1,r,Lson+1);
}
int main(){
  char status[2][2]={"0","1"};
  scanInt(N), scanInt(Q);
  // 不用建樹，初始化時所有的狀態都是false
  for(int act;Q--;){
    scanInt(act);
    if(act==1) //單點修改
      scanInt(Qr), Update(1,N,1);
    else //區間查詢
      scanInt(Ql), scanInt(Qr), puts(status[Query(1,N,1)]);
  }
}