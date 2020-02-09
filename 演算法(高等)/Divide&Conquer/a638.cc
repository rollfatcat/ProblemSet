// ZJ-a583比較：當 N 很小時，可以用 N^2 作法
// 題目已經保證：座標『已排序』且不會有重複的點
// 解法是 Divide and Conquer，做法類似MergeSort
#include<iostream>
#include<cmath>
using namespace std;
#define INF 0x7fffffffffffffff

struct nn{ long x, y; }node[3000000];
long NodeDis(int a, int b){
  return (node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y);
}
long NodeX(int a,int b){ return (node[a].x-node[b].x)*(node[a].x-node[b].x); }
long Divide(int l,int r,long* dis){
  if(l>=r) return INF;
  if(l==r-1)  return NodeDis(l,r);
  int m=(l+r)/2;
  *dis=min(*dis,Divide(l,m,dis));
  *dis=min(*dis,Divide(m+1,r,dis));
  // Merge
  for(int i=m; i>=l and NodeX(i,m)<*dis; i--)
    for(int j=m+1; j<=r and NodeX(i,j)<*dis; j++)
      *dis=min(*dis,NodeDis(i,j));
  return *dis;
}
int main(){
  int N;
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>node[i].x>>node[i].y;
  long dis=INF;
  dis=Divide(0,N-1,&dis);
  double ans=sqrt((double)dis);
  printf("%.4lf",ans);
}