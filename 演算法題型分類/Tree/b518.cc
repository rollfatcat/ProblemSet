// 題目要輸出所有從葉節點出發到達根節點的路徑
/* 反向思考：從根節點出發走完整棵樹，並且紀錄整個路程
 * 讀取時即可判斷是不是葉節點
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=100;
bool NotLeaf[MAXN];
vector<int> edge[MAXN];
vector<int> path[MAXN];

inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
void DFS_Path(int now){
  for(int to,i=0;i<edge[now].size();i++)
    to=edge[now][i],
    path[to]=path[now],
    path[to].push_back(to),
    DFS_Path(to);
}
int main(){
  int T, N, u, v, root;
  scanInt(T);
  for(int caseN=0;caseN<T;caseN++){
    if(caseN) puts("");
    memset(NotLeaf,0,sizeof(NotLeaf));
    edge[99].clear();
    for(int i=0;i<N;i++)
      edge[i].clear();
    scanInt(N);
    for(int i=0;i<N;i++)
      scanInt(u),
      scanInt(v),
      NotLeaf[v]=true,
      edge[v].push_back(u);
    path[edge[99][0]].clear();
    path[edge[99][0]].push_back(edge[99][0]);
    DFS_Path(edge[99][0]);
    for(int i=0;i<N;i++)
      if(NotLeaf[i]==0){
        printf("%d:",i);
        if(path[i].size()>2){
          putchar('{');
          printf("%d",path[i][path[i].size()-2]);
          for(int j=path[i].size()-3;j>0;j--)
            printf(",%d",path[i][j]);
          puts("}");
        }else
          puts("N");
      }
  }
}
/*
2
7
0,99
1,3
2,3
3,5
4,6
5,0
6,5
4
0,99
1,0
2,0
3,0
*/