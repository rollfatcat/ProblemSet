// 雖然題目沒說Query次數，但核心是RMQ => SegmentTree
#include<iostream>
using namespace std;

int deep[1000001]={0,1};
int node[1000001<<2], Ql, Qr;
bool scanInt(int &x){ char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0'); return c!=EOF; }
int DFS(long now){
  if(now<=1000000){ //計算過程中不重複算過的部分
    if(!deep[now])
      deep[now]=DFS( (now&1)?(3*now+1):(now>>1) )+1;
    return deep[now];
  }
  return DFS( (now&1)?(3*now+1):(now>>1) )+1;
}
void BuildTree(int l,int r,int idx){
  if(l==r){ node[idx]=deep[r]; return; }
  int m=(l+r)>>1, Lson=idx<<1;
  BuildTree(l,m,Lson),
  BuildTree(m+1,r,Lson+1);
  node[idx]=max(node[Lson],node[Lson+1]);
}
int Query(int l,int r,int idx){
  if(Ql<=l and r<=Qr) return node[idx];
  int m=(l+r)>>1, Lson=idx<<1;
  if(Qr<=m) return Query(l,m,Lson);
  if(Ql>m)  return Query(m+1,r,Lson+1);
  return max(Query(l,m,Lson),Query(m+1,r,Lson+1));
}
int main(){
  for(int idx=2; idx<=1000000; idx++)
    if(!deep[idx])
      deep[idx]=DFS( (idx&1)?(3*idx+1):(idx>>1) )+1;
  BuildTree(0,1000000,1);
  while(scanInt(Ql)){
    scanInt(Qr),
    printf("%d %d ",Ql,Qr);
    if(Ql>Qr) Ql^=Qr^=Ql^=Qr;
    printf("%d\n",Query(0,1000000,1));
  }
}