// 題目保證只有『線形』『環形』兩種可能的DNA => DFS簡單偵測環狀即可
/* (X)原本以為由上到下由左到右掃一遍，判斷起點的左邊和下面是不是都是'.'，是代表環不是代表線
 * => 範例第三筆測資就會發現這個方法有誤
 * (O)DFS只朝某一個有路可走的方向前進，當出現無法前進時判斷現在位置的周圍有幾個'.'，2個代表這是個環
 * => 範例第三筆測資可以發現當起點是線形時會被切成2條線判斷，但不影響結果
 */
#include<bits/stdc++.h>
using namespace std;

int R, C, size;
bool dna[30][30], vis[30][30];
bool DFS(int x,int y){
  vis[x][y]=1, size++;
  if(x>0 and !vis[x-1][y])  return DFS(x-1,y);
  if(y>0 and !vis[x][y-1])  return DFS(x,y-1);
  if(x+1<R and !vis[x+1][y]) return DFS(x+1,y);
  if(y+1<C and !vis[x][y+1]) return DFS(x,y+1);
  int point=0;
  if(x>0)   point+=(!dna[x-1][y]);
  if(y>0)   point+=(!dna[x][y-1]);
  if(x+1<R) point+=(!dna[x+1][y]);
  if(y+1<C) point+=(!dna[x][y+1]);
  return point==2;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  cin>>R>>C;
  char c;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      cin>>c, vis[i][j]=dna[i][j]=(c=='#');
  int cnt=0, sum=0;
  unsigned long mul=1;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      if(!vis[i][j]){
        size=0;
        if(DFS(i,j))
          cnt++, sum+=size, mul*=size;
      }
  cout<<cnt<<' '<<sum<<' '<<mul<<'\n';
}
/*
11 7
.......
.#####.
.#...#.
.#.#.#.
.#...#.
.#####.
.......
#######
#....#.
..##.#.
.###...
*/