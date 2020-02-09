// 利用 BIT 紀錄個數(但也可以用動態規劃的二維陣列解，參考v1)
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF=1<<30;
const int MAXN=1e5+1;
struct NODE{
  int r, h;
  bool operator<(const NODE &rhs)const{ return(h==rhs.h)?(r<rhs.r):(h<rhs.h); }
}data[MAXN];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
inline int lowbit(int x){ return -x&x; }
int main(){
  int N, qB;
  scanInt(N),
  scanInt(qB);

  for(int i=0;i<N;i++)
    scanInt(data[i].r),
    scanInt(data[i].h);
  // ---剪枝：需要的魔法陣個數是 0 時，不需計算體積直接輸出 0 ---
  if(qB==0){ puts("0"); return 0; }
  // 排序的序位：高度>半徑
  sort(data,data+N);
  int minV=INF, maxR=0;
  vector<int> BIT_R(101,0);
  // 前 K-1 個無論如何都不可能滿足題目要求，所以直接更新 BIT 和最大的半徑
  for(int i=0;i<qB-1;i++){
    maxR=max(maxR,data[i].r);
    for(int R=data[i].r;R<=100;R+=lowbit(R))
      BIT_R[R]++;
  }
  for(int i=qB-1;i<N;i++){
    // ---單點修改，修改半徑的個數---
    for(int R=data[i].r;R<=100;R+=lowbit(R))
      BIT_R[R]++;
    maxR=max(maxR,data[i].r);
    // ---連續和區間查詢，比現在半徑小的總數---
    for(int j=data[i].r;j<=maxR;j++){
      int cnt=0;
      for(int R=j;R>0;R-=lowbit(R))
        cnt+=BIT_R[R];
      if(cnt>=qB)
        minV=min(minV,(j*j*data[i].h)<<2);
    }
  }
  printf("%d\n",minV);
}