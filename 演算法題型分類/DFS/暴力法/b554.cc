// 地圖不大，DFS暴力解即可
#include<iostream>
using namespace std;

int N, maxL=0;
bool map[6][6],vis[6][6]={};
void DFS(int x,int y,int L){
  vis[x][y]=1;
  bool end=true;
  if(x>0 and map[x-1][y] and !vis[x-1][y])   DFS(x-1,y,L+1), end=false;
  if(x<N-1 and map[x+1][y] and !vis[x+1][y]) DFS(x+1,y,L+1), end=false;
  if(y>0 and map[x][y-1] and !vis[x][y-1])   DFS(x,y-1,L+1), end=false;
  if(y<N-1 and map[x][y+1] and !vis[x][y+1]) DFS(x,y+1,L+1), end=false;
  if(end and maxL<L) maxL=L;
  vis[x][y]=0;
}
int main(){
  cin>>N;
  char ch;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>ch, map[i][j]=(ch=='1');
  if(map[0][0])
    DFS(0,0,1);
  cout<<maxL<<endl;
}