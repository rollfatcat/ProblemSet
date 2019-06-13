// DFS走迷宮，題目保證路徑只有一條，輸出一路到底的寶藏位置
#include<iostream>
using namespace std;

bool map[20][20];
int N, M, edx, edy;
void DFS(int x,int y){
  map[x][y]=0;
  if(x-1>=0 and map[x-1][y]) DFS(x-1,y);
  else if(y-1>=0 and map[x][y-1]) DFS(x,y-1);
  else if(x+1<N and map[x+1][y]) DFS(x+1,y);
  else if(y+1<M and map[x][y+1]) DFS(x,y+1);
  else edx=x, edy=y;
}
int main(){
  int stx, sty;
  while(cin>>N>>M){
    string ss;
    for(int i=0;i<N;i++){
      cin>>ss;
      for(int j=0;j<M;j++){
        map[i][j]=ss[j]=='.';
        if(map[i][j] and (i==0 or j==0 or i==N-1 or j==M-1) )
          stx=i, sty=j;
      }
    }
    DFS(stx,sty);
    cout<<edx+1<<' '<<edy+1<<endl;
  }
}
/*
7 9
#########
##.....##
##.###.##
##.#...##
##.#.##..
#..#....#
#########
7 9
######.##
##.....##
##.####.#
##.#....#
##.#.##.#
#..#....#
#########
*/