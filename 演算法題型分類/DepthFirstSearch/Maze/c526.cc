// 不建圖去跑時間是5.6s，是先建立關係圖是3.2s
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;

int L, R, num[301];
bool use[301], hasAns;
vector<int> e[301];

void DFS(int deep){
  if(deep==R+1){ // 數字都有被使用到
    for(int i=L;i<=R;i++)
      printf("%d ",num[i]);
    printf("\n");
    hasAns=true;
    return;
  }
  int pre=num[deep-1];
  for(int i=0;i<e[pre].size() and !hasAns;i++)
    if(!use[e[pre][i]])
      num[deep]=e[pre][i],
      use[e[pre][i]]=1,
      DFS(deep+1),
      use[e[pre][i]]=0;
}
int main(){
  while(scanf("%d %d",&L,&R)==2){
    if(L==R){ puts("-1"); continue; }
    memset(use,0,sizeof(0));
    hasAns=false;
    // 先產生Graph(node和node間加起來是完全平方數就有一條無向edge)
    for(int i=L;i<=R;i++)
      e[i].clear();
    for(int i=L;i<=R;i++)
      for(int j=i+1;j<=R;j++){
        int root=sqrt(i+j);
        if((root*root)==(i+j))
          e[i].push_back(j), e[j].push_back(i);
      }
    // BruteForce
    for(int i=L;i<=R and !hasAns;i++)
      num[L]=i, use[i]=1, DFS(L+1), use[i]=0;
    if(!hasAns) puts("-1");
  }
}