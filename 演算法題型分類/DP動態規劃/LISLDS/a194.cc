// 將題目的要求轉為：反向求一個非嚴格遞增的 LIS, 或者是正向的一個非嚴格遞減的 LDS
// ZJ-a172 是本題的強化版(找LIS的時間必須壓縮到 N㏒N)
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000;
int num[MAXN];
int LIS[MAXN];

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
  for(int N;scanf("%d",&N)!=EOF;){
    // 原本要做反向找非嚴格遞增的LIS
    for(int i=0;i<N;i++)
      scanf("%d",&num[i]);
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
/*
5
5 4 3 2 1
7
1 3 5 8 2 6 7
*/