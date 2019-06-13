// 不用陣列存跑過的路線是1.7s
#include<iostream>
using namespace std;
#define MaxN 100
#define MaxH 105

int map[MaxN][MaxN], R, C;

int DFS(int x,int y){
    int path=0;
    // 邊界時要注意比較的格子要先存在才可以比較
    if(x>0 and map[x][y]>map[x-1][y]) path=max(path,DFS(x-1,y));
    if(y>0 and map[x][y]>map[x][y-1]) path=max(path,DFS(x,y-1));
    if(x<R-1 and map[x][y]>map[x+1][y]) path=max(path,DFS(x+1,y));
    if(y<C-1 and map[x][y]>map[x][y+1]) path=max(path,DFS(x,y+1));
    return path+1;
}
int main(){
  string ss;
  int T, maxDis;

  cin>>T;
  while(T--){
    cin>>ss>>R>>C;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>map[i][j];
    maxDis=0;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        maxDis=max(maxDis,DFS(i,j));
    cout<<ss<<": "<<maxDis<<endl;
  }
}