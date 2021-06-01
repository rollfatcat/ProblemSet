// No ProityQueue，類似 g053.cc，但更新方法有差異

#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
#define MaxNode 1001

int main(void){
  int map[MaxNode][MaxNode];
  int N, M, a, b, v, st, ed;

  while(cin>>N>>M and N and M){

    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        map[i][j]=0;
    while(M--)
      cin>>a>>b>>v, map[a][b]=map[b][a]=max(v,map[a][b]);

    cin>>st>>ed;

    int min_w[MaxNode];
    fill(min_w,min_w+MaxNode,0);

    queue<int>q;
    min_w[st]=1000000000;
    q.push(st);
    while(!q.empty()){
      a=q.front();  q.pop();
      for(int i=1;i<=N;i++)
        if(map[a][i]>0){
          int tmp_w=min(min_w[a], map[a][i]);
          if(min_w[i]<tmp_w)
            min_w[i]=tmp_w, q.push(i);
        }
    }
    cout<<min_w[ed]<<endl;
  }
}