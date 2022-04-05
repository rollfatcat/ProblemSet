//
#include<iostream>
#include<algorithm>
using namespace std;

int N, K, pos[50000];
bool CanCover(int L){
  int j=0, last=-1;
  for(int i=0;i<N and j<=K;i++)
    if(last<pos[i])
      j++, last=pos[i]+L;
  return j<=K;
}
int BS(int maxR){ // 左值＝未知，右值＝已知成功，範圍縮半時仍需要維持該特性
  int l=0, r=maxR, m;
  while(l<r){ //至少距離一個單位
    m=(l+r)>>1;
    if(CanCover(m)) r=m;
    else  l=m+1;
  }
  return l;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  while(cin>>N>>K){
    for(int i=0;i<N;i++)
      cin>>pos[i];
    sort(pos,pos+N);
    cout<<BS(pos[N-1]-pos[0])<<endl;
  }
}