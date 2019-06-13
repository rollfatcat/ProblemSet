// 切割後的隊伍，為了避免粉絲找不到所以一定會再附近(周圍8格)或者附近的附近(外圍16格)
// 也不會有令粉絲混亂的情況，比方說附近有兩隊人再排隊 => DFS只有一條路線，輸出尾端的最後一個點

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100


int R, C;
pair<int,int> End;
bool maze[MAXN][MAXN];

void DFS(int x,int y){

  maze[x][y]=0;
  bool IsEnd=true;
  // 判斷周圍(8格)優先
  if(x>=1  and maze[x-1][y]) DFS(x-1,y), IsEnd=false;
  if(y>=1  and maze[x][y-1]) DFS(x,y-1), IsEnd=false;
  if(y<C-1 and maze[x][y+1]) DFS(x,y+1), IsEnd=false;
  if(x<R-1 and maze[x+1][y]) DFS(x+1,y), IsEnd=false;
  if(x>=1 and y>=1  and maze[x-1][y-1]) DFS(x-1,y-1), IsEnd=false;
  if(x>=1 and y<C-1 and maze[x-1][y+1]) DFS(x-1,y+1), IsEnd=false;
  if(x<R-1 and y>=1  and maze[x+1][y-1]) DFS(x+1,y-1), IsEnd=false;
  if(x<R-1 and y<C-1 and maze[x+1][y+1]) DFS(x+1,y+1), IsEnd=false;

  // 判斷外圍(16格)
  if(y>=2  and maze[x][y-2]) DFS(x,y-2), IsEnd=false;
  if(y<C-2 and maze[x][y+2]) DFS(x,y+2), IsEnd=false;

  if(x>=2 and maze[x-2][y]) DFS(x-2,y), IsEnd=false;
  if(x>=2 and y>=2  and maze[x-2][y-2]) DFS(x-2,y-2), IsEnd=false;
  if(x>=2 and y>=1  and maze[x-2][y-1]) DFS(x-2,y-1), IsEnd=false;
  if(x>=2 and y<C-1 and maze[x-2][y+1]) DFS(x-2,y+1), IsEnd=false;
  if(x>=2 and y<C-2 and maze[x-2][y+2]) DFS(x-2,y+2), IsEnd=false;

  if(x>=1 and y>=2  and maze[x-1][y-2]) DFS(x-1,y-2), IsEnd=false;
  if(x>=1 and y<C-2 and maze[x-1][y+2]) DFS(x-1,y+2), IsEnd=false;

  if(x<R-1 and y>=2  and maze[x+1][y-2]) DFS(x+1,y-2), IsEnd=false;
  if(x<R-1 and y<C-2 and maze[x+1][y+2]) DFS(x+1,y+2), IsEnd=false;

  if(x<R-2 and maze[x+2][y]) DFS(x+2,y), IsEnd=false;
  if(x<R-2 and y>=2  and maze[x+2][y-2]) DFS(x+2,y-2), IsEnd=false;
  if(x<R-2 and y>=1  and maze[x+2][y-1]) DFS(x+2,y-1), IsEnd=false;
  if(x<R-2 and y<C-1 and maze[x+2][y+1]) DFS(x+2,y+1), IsEnd=false;
  if(x<R-2 and y<C-2 and maze[x+2][y+2]) DFS(x+2,y+2), IsEnd=false;

  if(IsEnd) End=make_pair(x,y);
}
int main(){

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int st, ed;
  while(cin>>R>>C and R){
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>maze[i][j];
    cin>>st>>ed;
    DFS(st,ed);
    cout<<End.first<<' '<<End.second<<endl;
  }
}