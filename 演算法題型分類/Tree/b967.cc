// DFS＋Adjancy List＋樹的構造概念 (0.8s/8.1MB)
/* 解法：從一個節點考慮最長邊的構成方式：
 * (1) 以該節點為折返點能到達的最長以及次長的邊組成
 * (2) 經過該節點往到達根節點方向組成的邊
 * 因此中間節點產生的最遠"血緣距離" 就是最遠 + 次遠
 * 而我們要找的就是這些值的最大值，至於這最遠、次遠要怎麼找呢?
 * 我們採用遞迴的方式，過程中從根節點出發，到達葉節點後把計算完的資訊丟給父節點，
 * 但我們只丟最遠距離，代表的是 parent 往 leaf 這方向最遠 node 的距離有多遠，但別忘了要加 1 ，因為 leaf 到 parent 差了一步
 * 當該 parent 接收完所有 leaves 的資訊後，它就有最遠和次遠資訊，接著將該 parent 視作 leaf 繼續往上更新
 */

#include<bits/stdc++.h>
using namespace std;

const int MAXN=100001;
int N, maxL;
vector<int> edge[MAXN];
bool NotRoot[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int DFS(int now){
  if(edge[now].size()==0) return 0;
  if(edge[now].size()==1) return DFS(edge[now][0])+1;
  int nowL[3]={ DFS(edge[now][0])+1, DFS(edge[now][1])+1 };
  if(nowL[0]<nowL[1])
    swap(nowL[0],nowL[1]);
  for(int i=2;i<edge[now].size();i++){
    nowL[2]=DFS(edge[now][i])+1;
    if(nowL[1]<nowL[2]) swap(nowL[1],nowL[2]);
    if(nowL[0]<nowL[1]) swap(nowL[0],nowL[1]);
  }
  maxL=max(maxL,nowL[0]+nowL[1]);
  return nowL[0];
}
int main(){
  int num, u, v, root, nowL;
  while(scanInt(N)){
    memset(NotRoot,0,sizeof(NotRoot));
    for(int i=0;i<N;i++)
      edge[i].clear();
    for(int i=1;i<N;i++)
      scanInt(u),
      scanInt(v),
      NotRoot[v]=1,
      edge[u].push_back(v);

    for(root=0;NotRoot[root];root++);
    maxL=0;
    printf("%d\n",max(maxL,DFS(root)));
  }
}
/*
8
0 1
0 2
0 3
7 0
1 4
1 5
3 6
4
0 1
0 2
2 3
*/