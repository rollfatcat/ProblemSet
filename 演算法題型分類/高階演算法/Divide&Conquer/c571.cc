// 原題目來自於：BZOJ-3262 陌上花开，但這題的要求是嚴格遞減(不可相等...)
/* (X)排序的第一維度後，第二第三維度用樹狀數組維護 => 10^6Ｘ10^6的陣列空間過大無法負荷
 * (O) 第一個維度用 CountSort 處理，第二維度透過分治法處理，第三維度是樹狀數組維護
 *     和 BZOJ-3262 比較：會把排序後的結果合併回去，但這題的話則不會確保第一第二維度的遞增
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
struct NODE{
  int y,z,o;
  NODE(int a=0,int b=0,int c=0):o(a),y(b),z(c){}
  bool operator<(const NODE &rhs)const{ return y<rhs.y; }
};
vector<NODE> bucket[MAXN];
int ans[MAXN];

class BIT{ // 以class形式封裝
  private:
    int arr[MAXN];
    inline int lowbit(int x){ return x&-x; }
  public:
    void update(int x,int v){
      for(;x<=MAXN;x+=lowbit(x))
        arr[x]+=v;
    }
    int query(int x,int v=0){
      for(;x;x-=lowbit(x))
        v+=arr[x];
      return v;
    }
}bit;
void CDQ(int,int);
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int N, x, y, z;
  scanInt(N);
  for(int i=0;i<N;i++)
    scanInt(x),
    scanInt(y),
    scanInt(z),
    bucket[N-x].push_back( NODE(i,N+1-y,N+1-z) );
  CDQ(0,N-1);
  // 輸出
  for(int i=0;i<N;i++)
    printf("%d\n",ans[i]);
}
void CDQ(int nL,int nR){
  if(nL==nR) return;
  int nM=(nL+nR)>>1;
  CDQ(  nL,nM);
  CDQ(nM+1,nR);
  // 下述的作法可以保證第一維度的嚴格遞增和第二維度的非嚴格遞增
  vector<NODE> dataL, dataR;
  for(int x=nL;x<=nM;x++)
    for(auto now:bucket[x])
      dataL.push_back(now);
  for(int x=nM+1;x<=nR;x++)
    for(auto now:bucket[x])
      dataR.push_back(now);
  sort(dataL.begin(),dataL.end());
  sort(dataR.begin(),dataR.end());
  // 第三維度用樹狀數組維護
  int iL=0, iR=0;
  while(iR<dataR.size()){
    while(iL<dataL.size() and dataL[iL].y<dataR[iR].y)
      bit.update(dataL[iL++].z,1);
    ans[ dataR[iR++].o ]+=bit.query( dataR[iR].z-1 );
  }
  for(int i=0;i<iL;i++)
    bit.update(dataL[i].z,-1);
}
/*
3
1 1 1
2 2 2
3 3 3

10
7 2 6
8 6 4
6 6 3
3 1 7
8 7 8
8 7 2
7 10 1
5 6 4
1 3 1
7 3 1
*/