// BIT處理y軸座標的個數問題，因為題目要求輸入的順序輸出Rank值所以要一並紀錄輸入順序
// 因為輸入的ＸＹ座標落在 1≦ x , y ≦1000，可以用BIT，若沒給上限就得做離散化。
/* BIT 版本(66ms) vs Divide＆Conquer 版本(0.2s)
 * (1) 根據Ｘ座標再根據Ｙ座標排序
 * (2) 由Ｘ座標小的取出來，只要Ｘ座標相同就把這個座標加入待處理的區間
 * 等到Ｘ座標不同時，把待處理區間的點一個個取出根據Ｙ座標做查詢(利用BIT查詢比這個Ｙ座標小的個數)
 * 查詢結束後才更新待處理區間內的Ｙ座標，注意最後一次的待處理區間要清空。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000;
int BIT[1001];
int RK[MAXN];
pair< pair<short,short>,short > node[MAXN];

inline bool scanInt(short &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
inline int lowbit(int x){ return x&-x;}
int main(){
  short N, nowx, x, y, Qst, Qed;
  while(scanInt(N)){
    for(short i=0;i<N;i++)
      scanInt(node[i].first.first),
      scanInt(node[i].first.second),
      node[i].second=i;
    sort(node,node+N);

    memset(BIT,0,sizeof(BIT));
    memset(RK,0,sizeof(RK));
    nowx=node[0].first.first;
    Qst=Qed=0;
    for(short idx=1;idx<N;idx++)
      if(nowx==node[idx].first.first)
        Qed=idx;
      else{
        for(int tag=Qst;tag<=Qed;tag++)
          for(int pos=node[tag].first.second-1;pos;pos-=lowbit(pos))
            RK[ node[tag].second ]+=BIT[pos];
        for(int tag=Qst;tag<=Qed;tag++)
          for(int pos=node[tag].first.second;pos<=1000;pos+=lowbit(pos))
            BIT[pos]++;
        nowx=node[idx].first.first;
        Qst=Qed=idx;
      }
    // 清空待處理區間
    for(int tag=Qst;tag<=Qed;tag++)
      for(int pos=node[tag].first.second-1;pos;pos-=lowbit(pos))
        RK[ node[tag].second ]+=BIT[pos];
    //
    for(short i=0;i<N;i++)
      printf("%d\n",RK[i]);
  }
}