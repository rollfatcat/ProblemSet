// 因為數量級高達1e5個，LIS時間必須得壓縮到N㏒N
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000;
int num[MAXN];
int LIS[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
// 變形的二分搜尋，讓LIS的時間加速到N㏒N
inline int BinarySearch(int nL,int nR,int Len,int t){
  for(int nM;nR>=nL;){
    nM=(nL+nR)>>1;
    if(LIS[nM]<=t){
      if(nM==Len or LIS[nM+1]>t)
        return nM+1;
      nL=nM+1;
    }else
      nR=nM-1;
  }
  return 0;
}
int main(){
  for(int N;scanInt(N);){
    // 原本要做反向找非嚴格遞增的LIS
    for(int i=0;i<N;i++)
      scanInt(num[i]);
    // DP_LIS
    int L=0, set=0;
    LIS[0]=num[N-1]; // 先推一個進去LIS
    for(int i=N-2;i>=0;i--){
      set=BinarySearch(0,L,L,num[i]);
      LIS[set]=num[i];
      L=max(L,set);
    }
    printf("%d\n",L+1);
  }
}