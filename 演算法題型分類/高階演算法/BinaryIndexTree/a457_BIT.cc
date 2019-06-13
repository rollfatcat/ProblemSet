// (難點)如何將原問題轉換成：求#逆數對 => 離散化＋BIT or MergeSort解(CDQ分治法)
// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1324032415
/* 差異分數定義： |{ (i,j) |(Ai>Aj and Bi<Bj) or (Ai<Aj and Bi>Bj),1≤i<j≤k }|.
 * 觀察上面的定義後可以發現 :
 * (1) (i,j)的關係是 Ai>Aj 只要計算符合 Bi<Bj 的數對個數(逆數對)
 * (2) (i,j)的關係是 Ai<Aj 需要計算符合 Bi>Bj 的數對個數 => 這時交換把(i,j)這組數據位置交換，就變成情況(1)
 * (3) (i,j)的關係是 Ai=Aj 不需要計算 => 以逆數對來看設法維持 Bi>Bj 的順序即可
 * 先將所有數據對 data[i]=(A,B) 依照『A』由大排到小，且一樣時就按照『B』由大到小(逆數對來看個數=0)
 * 對排序完成的數列找出全部的逆數對即可。
 * 題解說明：其實不用理會 i<j 的關係，排序之後計算也是不變的。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100002;
int numN;
int ord[MAXN];
int BIT[MAXN];
struct DATA{
  int a, b;
  bool operator<(const DATA &rhs)const{ return (a==rhs.a)?(b>rhs.b):(a>rhs.a); }
}data[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x; }
inline int Query(int now,int out=0){
  for(int idx=now;idx>0;idx-=lowbit(idx))
    out+=BIT[idx];
  return out;
}
inline void Update(int now){
  for(int idx=now;idx<=numN;idx+=lowbit(idx))
    BIT[idx]++;
}
int main(){
  int N, maxS;
  scanInt(N),
  scanInt(maxS);

  for(int i=0;i<N;i++)
    scanInt(data[i].a);
  for(int i=0;i<N;i++)
    scanInt(data[i].b),
    ord[i]=data[i].b;

  sort(data,data+N);
  // 離散化
  sort(ord,ord+N);
  numN=unique(ord,ord+N)-ord;
  // BIT
  long res=0;
  for(int i=0;i<N;i++){
    int pos=lower_bound(ord,ord+numN,data[i].b)-ord+1;
    res+=Query(pos-1);
    Update(pos);
  }
  printf("%ld\n",res);
}
/*
5 10
3 7 5 5 8
4 6 7 5 8
5 10
3 7 5 5 8
4 6 7 7 7
*/