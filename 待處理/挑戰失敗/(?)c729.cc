// 好像不是暴力法+貪婪法填格子
#include<iostream>
#include<cstring>
using namespace std;

int R, C;
int stepR, stepC;
bool map[50][50];
void DFS(int x,int y){
  map[x][y]=0;
  if(x+stepC<R and y>=stepR and map[x+stepC][y-stepR]) DFS(x+stepC,y-stepR);
  else if(x+stepC<R and y+stepR<C and map[x+stepC][y+stepR]) DFS(x+stepC,y+stepR);
  else if(x+stepR<R and y>=stepC  and map[x+stepR][y-stepC]) DFS(x+stepR,y-stepC);
  else if(x+stepR<R and y+stepC<C and map[x+stepR][y+stepC]) DFS(x+stepR,y+stepC);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(char ch;cin>>R>>C>>stepR>>stepC;){
    if(stepR<stepC)
      swap(stepR,stepC);
    memset(map,0,sizeof(map));
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>ch, map[i][j]=(ch=='.');
    int source=0;
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        if(map[i][j])
          source++, DFS(i,j);
    printf("%d\n",source);
  }
}