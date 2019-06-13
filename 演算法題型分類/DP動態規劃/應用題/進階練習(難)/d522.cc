// 題解：http://mypaper.pchome.com.tw/zerojudge/post/1322381459
// 和 d404-uva10285 的DFS做對比
// 格子的數值可能是負的
/* 雖然移動方式是上下左右的四個方向，但題目要求移動到下一個格子上的數字必須大於現在的格子
 * 從某個的格子出發能走到的最大價值走過後必須記錄起來
 * 從最低數值的格子開始更新，如果這一格的DP解沒有被更新過就跳開
 * 題目規定需要從左上角出發，一開始只有DP[0][0]有值，其他初始化時是-2^31，代表沒更新過
 */
#include<bits/stdc++.h>
using namespace std;
#define unvis 1<<31

int map_data[102][102];
int DP[102][102], ans;
struct nn{
  int x,y,v;
  bool operator<(const nn &other)const{ return v<other.v; }
}grid[10002];
inline void scanInt(int &x){ //題目提到測資的整數之間的空白和換行會亂跳
  char c;
  while((c=getchar())==' ' or c=='\n');
  bool sign;
  if(c=='-')  x=0, sign=1;
  else x=c-'0', sign=0;
  for(;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign)  x=-x;
}

int main(){
  int N, K;
  scanInt(N), scanInt(K);
  int num=0;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      scanInt(map_data[i][j]),
      DP[i][j]=unvis,
      grid[num++]={i,j,map_data[i][j]};
  sort(grid,grid+num);

  int move[4]={-1,1,0,0};
  ans=DP[0][0]=map_data[0][0];
  for(int idx=0;idx<num;idx++){
    int x=grid[idx].x,
        y=grid[idx].y;
    if(DP[x][y]==unvis) continue;
    for(int dir=0;dir<4;dir++)
      for(int step=1;step<=K;step++){
        int tx=x+step*move[dir],
            ty=y+step*move[3-dir];
        if(tx>=0 and tx<N and ty>=0 and ty<N and map_data[x][y]<map_data[tx][ty]){
          int tv=DP[x][y]+map_data[tx][ty];
          if(tv>DP[tx][ty])
            DP[tx][ty]=tv, ans=max(ans,tv);
        }
      }
  }
  printf("%d\n",ans);
}
/*
3 3
1 3 2
4 9 5
6 8 7
*/