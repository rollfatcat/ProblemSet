// 裸題：照模板做即可，空間限定是64MB
#include<bits/stdc++.h>
using namespace std;
#define MaxN 300001

int data[MaxN], N, w, qL, qR;
int nodeMax[MaxN<<2],nodeMin[MaxN<<2];
void BuiltTree(int l,int r,int idx){
  if(l==r){ nodeMax[idx]=nodeMin[idx]=data[r]; return; }
  int m=(l+r)>>1, Lson=idx<<1;
  BuiltTree(l,m,Lson), BuiltTree(m+1,r,Lson+1);
  nodeMax[idx]=max(nodeMax[Lson],nodeMax[Lson+1]);
  nodeMin[idx]=min(nodeMin[Lson],nodeMin[Lson+1]);
}
int QueryMax(int l,int r,int idx){
  if(qL<=l and r<=qR) return nodeMax[idx];
  int m=(l+r)>>1, Lson=idx<<1;
  if(qR<=m) return QueryMax(l,m,Lson);
  if(qL>m)  return QueryMax(m+1,r,Lson+1);
  return max(QueryMax(l,m,Lson),QueryMax(m+1,r,Lson+1));
}
int QueryMin(int l,int r,int idx){
  if(qL<=l and r<=qR) return nodeMin[idx];
  int m=(l+r)>>1, Lson=idx<<1;
  if(qR<=m) return QueryMin(l,m,Lson);
  if(qL>m)  return QueryMin(m+1,r,Lson+1);
  return min(QueryMin(l,m,Lson),QueryMin(m+1,r,Lson+1));
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N>>w and N){
    for(int i=1;i<=N;i++)
      cin>>data[i];
    BuiltTree(1,N,1);
    vector<int> ans;
    int minD=0x7fffffff;
    for(qL=1,qR=w; qR<=N; qL++,qR++){
      int tmpD=QueryMax(1,N,1)-QueryMin(1,N,1);
      if(minD>tmpD) minD=tmpD, ans.clear();
      if(minD==tmpD) ans.push_back(qR);
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++)
      cout<<(ans[i]-w+1)<<' '<<ans[i]<<'\n';
  }
}