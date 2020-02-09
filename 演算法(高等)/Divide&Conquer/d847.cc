// 解法是 Divide and Conquer，做法類似MergeSort
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, output[10000];
struct nn{ int x, y, no, r; }node[10000], tmp[10000];
bool compare(nn a,nn b){ return(a.x==b.x)?(a.y>b.y):(a.x<b.x); }
void DivCon(int l,int r){
  if(l>=r) return;
  int m=(l+r)/2;
  DivCon(l,m);
  DivCon(m+1,r);
  // Merge
  int i=l, j=m+1, k=l, d=0;
  while(i<=m and j<=r)
    if(node[i].y<node[j].y) tmp[k++]=node[i++];
    else  node[j].r+=(i-l), tmp[k++]=node[j++];
  while(i<=m) tmp[k++]=node[i++];
  while(j<=r) node[j].r+=(i-l), tmp[k++]=node[j++];
  for(i=l; i<=r; i++)
    node[i]=tmp[i];
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N){
    for(int i=0;i<N;i++)
      cin>>node[i].x>>node[i].y, node[i].no=i, node[i].r=0;
    sort(node,node+N,compare);
    DivCon(0,N-1);
    for(int i=0;i<N;i++)
      output[node[i].no]=node[i].r;
    for(int i=0;i<N;i++)
      cout<<output[i]<<endl;
  }
}