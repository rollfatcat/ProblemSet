// 二分圖著色問題且題目不保證是聯通( 類似 ZJd768-UVa10004 的 BiColoring )
// 如果可以二分化所有的點，輸出最少的那一群點量
// 枚舉所有未塗色的點當作起點，DFS 跑遍以該起點聯通的所有點
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
int color_cnt[2];
vector<int> Edge[MAXN];
vector<int> color;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
bool BiPartion(int now,bool nowC){
  // 檢查其他相連的點顏色是否和現在顏色衝突(?)
  bool fail=0;
  vector<int>::iterator it;
  for(it=Edge[now].begin();it!=Edge[now].end() and fail==0;it++)
    fail=(color[*it]==nowC);
  color[now]=nowC,
  color_cnt[nowC]++;
  for(it=Edge[now].begin();it!=Edge[now].end();it++)
    if(color[*it]==-1)
      fail|=BiPartion(*it,nowC^1)==0;
  return (fail==0);
}
int main(){
  int Nnode, Nedge, u, v;
  scanInt(Nnode),
  scanInt(Nedge);
  while(Nedge--)
    scanInt(u),
    scanInt(v),
    Edge[u].push_back(v),
    Edge[v].push_back(u);
  color.assign(Nnode+1,-1);
  bool success=1;
  int ans=0;
  for(int i=1;i<=Nnode and success;i++)
    if(color[i]==-1){
      color_cnt[0]=color_cnt[1]=0;
      success=BiPartion(i,0);
      ans+=min(color_cnt[0],color_cnt[1]);
    }
  printf("%d\n",(success)?ans:0);
}