// 固定往外走3步(DFS)，因為每個格子都價值至少是1，換句話說走過的格子就不該回頭
// T ≤ 150 and 2 ≤ N,M ≤ 50 => 150*2500*64

#include<iostream>
using namespace std;
#define MAXN 52

short caseT, R, C;
short mapv[MAXN][MAXN];
bool gone[MAXN][MAXN]={};
int DFS(int x,int y,int depth){
  if(depth==3) return mapv[x][y];
  int nowv=0;
  gone[x][y]=1;
  if(x>0 and gone[x-1][y]==0) nowv=max(nowv,DFS(x-1,y,depth+1));
  if(y>0 and gone[x][y-1]==0) nowv=max(nowv,DFS(x,y-1,depth+1));
  if(x<R-1 and gone[x+1][y]==0) nowv=max(nowv,DFS(x+1,y,depth+1));
  if(y<C-1 and gone[x][y+1]==0) nowv=max(nowv,DFS(x,y+1,depth+1));
  gone[x][y]=0;
  return mapv[x][y]+nowv;
}

int main(){

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  cin>>caseT;
  while(caseT--){
    cin>>R>>C;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>mapv[i][j];
    int maxv=0, nowv;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        nowv=DFS(i,j,0),
        maxv=max(maxv,nowv);
    cout<<maxv<<'\n';
  }
}