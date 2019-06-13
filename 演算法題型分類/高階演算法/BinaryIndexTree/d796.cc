// 二維BIT實作，要求區間查詢和單點修改
// 題解(細節有誤)：https://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/
#include<iostream>
using namespace std;

int N, BIT[251][251]={}; //加總最大是 32767*62500
inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x; }
inline int getSum(int x,int y){
  int sum=0;
  for(int i=x;i>0;i-=lowbit(i))
    for(int j=y;j>0;j-=lowbit(j))
      sum+=BIT[i][j];
  return sum;
}
int query(int x1,int y1,int x2,int y2){
  int lx=min(x1,x2)-1,  rx=max(x1,x2),
      ly=min(y1,y2)-1,  ry=max(y1,y2);
  int v1=getSum(rx,ry);
  int v2=getSum(lx,ry);
  int v3=getSum(rx,ly);
  int v4=getSum(lx,ly);
  return v1+v4-v2-v3;
}
void update(int x,int y,int v){
  for(int i=x;i<=N;i+=lowbit(i))
    for(int j=y;j<=N;j+=lowbit(j))
      BIT[i][j]+=v;
}
int main(){
  int Q;
  scanInt(N), scanInt(Q);
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      scanInt(BIT[i][j]);
  // construct
  for(int i=1;i<=N;i++) //水平整合
    for(int j=1;j<=N;j++){
      int up_layer=j+lowbit(j);
      if(up_layer<=N)
        BIT[i][up_layer]+=BIT[i][j];
    }
  for(int i=1;i<=N;i++) //垂直整合
    for(int j=1;j<=N;j++){
      int up_layer=i+lowbit(i);
      if(up_layer<=N)
        BIT[up_layer][j]+=BIT[i][j];
    }
  //
  for(int act,x1,x2,y1,y2; Q--;){
    scanInt(act);
    if(act==1)
      scanInt(x1), scanInt(y1), scanInt(x2), scanInt(y2),
      printf("%d\n",query(x1,y1,x2,y2));
    else
      scanInt(x1), scanInt(y1), scanInt(x2),
      update(x1,y1,x2-query(x1,y1,x1,y1));
  }
}
/*
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16

 1  3  3 10
 5 11  7 26
 9 19 11 42
13 27 15 58

 1  3  3  10
 6 14 10  36
 9 19 11  42
28 60 36 136
*/