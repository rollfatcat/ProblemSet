// DFS實作(無剪枝) 5.2s
#include<iostream>
#include<cstring>
using namespace std;

//dir=0：橫走 1：直走
int n, m, MaxStep;
bool vis[11][11];
void DFS(int x,int y,int step,bool nowD){
  vis[x][y]=1, nowD^=1;
  bool GoDeep=false;
  if(nowD){
    if(x>0 and !vis[x-1][y])  GoDeep=1, DFS(x-1,y,step+1,nowD);
    if(x+1<n and !vis[x+1][y])GoDeep=1, DFS(x+1,y,step+1,nowD);
  } else {
    if(y>0 and !vis[x][y-1])  GoDeep=1, DFS(x,y-1,step+1,nowD);
    if(y+1<m and !vis[x][y+1])GoDeep=1, DFS(x,y+1,step+1,nowD);
  }
  if(!GoDeep and step>MaxStep)
    MaxStep=step;
  vis[x][y]=0;
}
int main(){
  cin>>n>>m;
  memset(vis,0,sizeof(vis));
  MaxStep=vis[0][0]=1;
  if(n>1)
    DFS(1,0,2,1);
  if(m>1)
    DFS(0,1,2,0);
  cout<<MaxStep<<endl;
}