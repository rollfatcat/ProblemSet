// (離線處理=>莫隊) 89%(11% TLE，猜測是卡在當除數很小但是暴力法查詢倍數導致的TLE)
/* 根據theshold決定採用莫隊還是二分搜尋法計算(1s/253MB)
 * 訂一個 threshold 來決定當除數小於時透過『二分搜尋法』計算區間內可以被該除數整除的個數
 * ，若大於等於則採用莫隊算法處理，這時即便是暴力查詢倍數時間成本也是Ｋ√Ｎ，Ｋ＝√Ｎ/threshold。
 ***** 二分搜尋法和前綴和的兩者版本差異： *****
 * 前綴和版本雖然查詢成本降為O(1) 但是為了維護所有小於threshold的前綴和，
 * 多算一個數字時的更新成本增加為O(threshold)
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 300001

const int SQTN=51;
vector<int> pos[SQTN];
int N, Bsz;
int org[MAXN];
int cnt[MAXN];
int ans[MAXN];
struct QUERY{
  int L,R,v,o;
  QUERY(int l=0,int r=0,int v=0,int o=0):L(l),R(r),v(v),o(o){}
  bool operator<(const QUERY &rhs)const{ return (L/Bsz)<(rhs.L/Bsz) or (L/Bsz)==(rhs.L/Bsz) and R<rhs.R; }
} query[MAXN];

inline void add(int x){ cnt[x]++; }
inline void sub(int x){ cnt[x]--; }

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){

  int Q, qL, qR, qV;
  scanInt(N);
  scanInt(Q);
  Bsz=ceil(sqrt(N));
  for(int i=1;i<=N;i++){
    scanInt(org[i]);
    for(int fac=2;fac<SQTN;fac++)
      if(org[i]%fac==0)
        pos[fac].push_back(i);
  }

  int tot=0;
  for(int i=0;i<Q;i++){
    scanInt(qL),
    scanInt(qR),
    scanInt(qV);
    if(qV<SQTN) // 小於 threshold 直接二分搜尋法找落在區間內的個數
      ans[i]=(qV==1)? (qR-qL+1): (upper_bound(pos[qV].begin(),pos[qV].end(),qR)-lower_bound(pos[qV].begin(),pos[qV].end(),qL));
    else // 大於等於 threshold，莫隊離散作法
      query[tot++]=QUERY(qL,qR,qV,i);
  }

  sort(query,query+tot);
  int nowL=0, nowR=0;
  for(int i=0;i<tot;i++){
    if(query[i].v>=SQTN){
      while(nowL<query[i].L) sub(org[nowL++]);
      while(nowL>query[i].L) add(org[--nowL]);
      while(nowR>query[i].R) sub(org[nowR--]);
      while(nowR<query[i].R) add(org[++nowR]);
    }
    // QueryCnt()
    for(int j=query[i].v; j<=N; j+=query[i].v)
      ans[ query[i].o ]+=cnt[j];
  }
  for(int i=0;i<Q;i++)
    printf("%d\n",ans[i]);
}