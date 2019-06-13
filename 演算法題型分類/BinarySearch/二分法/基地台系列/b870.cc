// 類似 APCS 20170304的第4題-基地台，只是輸出半徑
#include<iostream>
#include<algorithm>
using namespace std;

int N, K, pos[100000];
bool CanCover(int L){
  int j=0, last=-1;
  for(int i=0;i<N and j<=K;i++)
    if(last<pos[i])
      j++, last=pos[i]+L;
  return j<=K;
}
int BS(int maxR){
  int l=0, r=maxR, m;
  while(l<r){
    m=(l+r)>>1;
    if(CanCover(m)) r=m;
    else  l=m+1;
  }
  return l;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  int T;

  for(cin>>T; T--; ){
    cin>>N>>K;
    for(int i=0;i<N;i++)
      cin>>pos[i];
    sort(pos,pos+N);
    int R=BS(pos[N-1]-pos[0]);
    R=(R>>1)+(R&1);
    cout<<R<<endl;
  }
}