// (0.4s) 線段樹樸素遞迴解法：http://kenby.iteye.com/blog/954112

#include<iostream>
using namespace std;
#define MaxN 500001

struct nn{
  long sum; //範圍內的加總
  long add; //範圍內的增量
} node[MaxN<<1];
int data[MaxN], N;
void BuildTree(int idx,int l,int r){
  node[idx].add=0; // 初始化時增量=0
  if(l==r){  node[idx].sum=data[l]; return; }
  int m=(l+r)>>1, left=idx<<1;
  BuildTree(left,l,m);
  BuildTree(left+1,m+1,r);
  node[idx].sum=node[left].sum+node[left|1].sum;
}
long Query(int idx,int l,int r,int Qx,int Qy,int add){ // 累计增量，深度遍历求和的时候用到
  // 一条匹配线段找到，计算它的和，然后加给原始线段的和
  if(l==Qx and r==Qy){ return node[idx].sum+(Qy-Qx+1)*add; }
  int m=(l+r)>>1, left=idx<<1;
  // 若不是匹配线段，更新增量，继续往下找
  if(m>=Qy)
    return Query(left,l,m,Qx,Qy,add+node[idx].add);
  else if(m<Qx)
    return Query(left+1,m+1,r,Qx,Qy,add+node[idx].add);
  else
    return Query(  left,  l,m, Qx, m,add+node[idx].add)+
           Query(left|1,m+1,r,m+1,Qy,add+node[idx].add);
}
void update(int idx,int l,int r,int Qx,int Qy,long add){
  // 覆盖匹配线段的那些线段，都要更新sum值，匹配线段本身也包括在内
  node[idx].sum+=(Qy-Qx+1)*add;
  // 只有匹配线段才更新增量值
  if(l==Qx and r==Qy){ node[idx].add+=add; return; }
  int m=(l+r)>>1, left=idx<<1;
  if(m>=Qy)
    update(left,l,m,Qx,Qy,add);
  else if(m<Qx)
    update(left+1,m+1,r,Qx,Qy,add);
  else
    update(left,l,m,Qx,m,add),
    update(left+1,m+1,r,m+1,Qy,add);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int M, v, x, y, k;
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>data[i];
  BuildTree(1,1,N);
  for(cin>>M; M--; ){
    cin>>v>>x>>y;
    if(v==2)
      cout<<Query(1,1,N,x,y,0)<<endl;
    else
      cin>>k,
      update(1,1,N,x,y,k);
  }
}
