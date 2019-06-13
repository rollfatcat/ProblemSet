#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
#define MaxNode 101
#define MaxP 201


int main(void){
  int map[MaxNode][MaxNode];
  int T,N,L;
  cin>>T;
  while(T--){
    cin>>N>>L;
    for(int i=0;i<=N;i++)
      for(int j=0;j<=N;j++)
        map[i][j]=MaxP;
    int a, b, v;
    while(L--)
      cin>>a>>b>>v, map[a][b]=map[b][a]=v;

    int dfs[MaxNode];
    fill(dfs,dfs+MaxNode,MaxP);
    dfs[1]=0;

    queue<int>q;
    q.push(1);
    while(!q.empty()){
      a=q.front();
      q.pop();
      for(int i=1;i<=N;i++)
        if(map[a][i]<MaxP){
          int tmp_dfs=max(dfs[a], map[a][i]);
          if(dfs[i]>tmp_dfs)
            dfs[i]=tmp_dfs, q.push(i);
        }
    }
    cout<<dfs[N]<<endl;
  }
}