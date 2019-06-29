// 95%卡最後一行會多輸出一個1
#include<iostream>
#include<vector>
using namespace std;

vector<int> e[10001];
int N, M, group[10001], number;
inline char scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c;}
void DFS(int now){
  if(group[now]>=0) return;
  group[now]=number;
  for(int i=0;i<e[now].size();i++)
    if(group[e[now][i]]<0)
      DFS(e[now][i]);
}
int main(){
  while(scanInt(N)!=EOF and scanInt(M)!=EOF){
    for(int i=0;i<=N;i++)
      e[i].clear(), group[i]=-1;
    int u, v;
    for(int i=0;i<M;i++){
      scanInt(u);
      while(scanInt(v)!='\n')
        e[u].push_back(v), e[v].push_back(u);
      e[u].push_back(v), e[v].push_back(u);
    }
    scanInt(u);
    for(int i=0;i<u;i++)
      scanInt(v), e[0].push_back(v), e[v].push_back(0);
    number=0;
    for(int i=0;i<=N;i++)
      if(group[i]<0)
        DFS(i), number++;
    printf("%d\n",number);
    if(getchar()==EOF) break;
  }
}