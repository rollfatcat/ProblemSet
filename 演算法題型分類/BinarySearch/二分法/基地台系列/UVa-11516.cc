#include<bits/stdc++.h>
using namespace std;

int N, K, pos[100001];
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

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){

  int caseT;
  scanInt(caseT);
  while(caseT--){
    scanInt(K);
    scanInt(N);
    for(int i=0;i<N;i++)
      scanInt(pos[i]);
    sort(pos,pos+N);
    double R=BS(pos[N-1]-pos[0]);
    printf("%.1lf\n",R/2.0);
  }
}