// (暴力法＋二分法)注意怎麼從現在推到 SubProblem
// 範圍縮減時必定保證 r 是可以的
// SE
#include<iostream>
#include<stdlib.h>
using namespace std;
int N, K;
long long pos[50000];

int compare(const void *a, const void *b){ return *(long long*)a-*(long long*)b; }
bool CanCover(long long size){
  int idx=0;
  for(int i=0;i<K;i++){
    for(long long ed=pos[idx++]+size; idx<N and pos[idx]<=ed; idx++);
    // 基地台還沒耗完，但已經可以涵蓋全部範圍
    if(idx>=N)
      return true;
  }
  return idx>=N;
}
long long BS(long long l, long long r){
  while(l<r){
    long long mid=(l+r)/2;
    if( CanCover(mid) )
      r=mid;
    else
      l=mid+1;
    if(l==r)
      return r;
  }
  return r;
}
int main(void){
  while(cin>>N>>K){
    for(int i=0;i<N;i++)
      cin>>pos[i];
    qsort(pos,N,sizeof(pos[0]),compare);
    cout<<BS(0,pos[N-1]-pos[0])<<endl;
  }
}