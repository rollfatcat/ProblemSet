// DFS 玩家輪流
#include<iostream>
using namespace std;

int N, map[4][4];
int cnt[3],score[2];
bool vis[4][4];

int WhoWins(){
  return (score[0]==score[1])?2:(score[0]<score[1]);
}
void DFSA(int now);
void DFSB(int now);
int main(){
  while(cin>>N and N){
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        cin>>map[i][j], vis[i][j]=false;
    cnt[0]=cnt[1]=cnt[2]=0;
    score[0]=score[1]=0;
    DFSA(0);
    cout<<cnt[0]<<' '<<cnt[1]<<' '<<cnt[2]<<endl;
  }
}
void DFSB(int now){ // B的回合
  bool flag=true;
  for(int i=0;i<N;i++){
    flag=flag&vis[i][now];
    if(!vis[i][now]){
      vis[i][now]=true, score[1]+=map[i][now];
      DFSA(i);
      vis[i][now]=false, score[1]-=map[i][now];
    }
  }
  //沒得選, 比較分數後決定勝者
  if(flag){
    cnt[WhoWins()]++;  return;
  }
}
void DFSA(int now){ // A的回合
  bool flag=true;
  for(int i=0;i<N;i++){
    flag=flag&vis[now][i];
    if(!vis[now][i]){
      vis[now][i]=true, score[0]+=map[now][i];
      DFSB(i);
      vis[now][i]=false, score[0]-=map[now][i];
    }
  }
  //沒得選, 比較分數後決定勝者
  if(flag){
    cnt[WhoWins()]++; return;
  }
}