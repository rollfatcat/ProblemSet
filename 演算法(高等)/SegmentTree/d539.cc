// RMQ=Range Minimum/Maximum Query
// 基礎說明參考：https://blog.csdn.net/emailed/article/details/4761806
// 為何SegmentTree的空間需求是4N：https://blog.csdn.net/Monster_Day/article/details/52214711
#include<iostream>
using namespace std;
#define MaxN 500001

int data[MaxN], node[MaxN<<1];
void BuildTree(int l,int r,int idx){
  if(l==r){  node[idx]=data[l]; return; }
  int m=(l+r)/2, lson=2*idx, rson=lson+1;
  BuildTree(  l,m,lson);
  BuildTree(m+1,r,rson);
  node[idx]=max(node[lson],node[rson]);
}
int query(int l,int r,int idx,int x,int y){
  if(l==x and r==y) return node[idx];
  int m=(l+r)/2;
  if(m>=y)      return query(  l,m,  2*idx,x,y);
  else if(m<x)  return query(m+1,r,2*idx+1,x,y);
  else return max( query(l,m,2*idx,x,m), query(m+1,r,2*idx+1,m+1,y) );
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  int N, M;
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>data[i];
  BuildTree(1,N,1);
  cin>>M;
  for(int l,r;M--;){
    cin>>l>>r;
    if(l>r) l^=r^=l^=r;
    cout<<query(1,N,1,l,r)<<endl;
  }
}