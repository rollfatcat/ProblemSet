// DFS拜訪Tree, 計算 #Children Node
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 20001

int n;
int cnt[MaxN];
vector<int> e[MaxN];
int DFS(int now){
  if(cnt[now]>0)
    return 0;
  cnt[now]=1;
  for(int i=0;i<e[now].size();i++)
    cnt[now]+=DFS(e[now][i]);
  return cnt[now];
}
int main(){
  int a, b;
  while(cin>>n){
    for(int i=1;i<=n;i++)
      e[i].clear(),
      cnt[i]=0;
    for(int i=1;i<n;i++)
      cin>>a>>b,
      e[a].push_back(b),
      e[b].push_back(a);
    DFS(1);
    for(int i=1;i<=n;i++)
      printf("%5d-%5d\n",i,cnt[i]);
  }
}