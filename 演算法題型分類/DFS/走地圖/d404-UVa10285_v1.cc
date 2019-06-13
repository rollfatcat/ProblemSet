// 嚴格遞減, 注意當目前的點是最低點時長度至少是1
// 測第11筆測資就知道, 如果不是嚴格遞減會輸出10
// 不判斷邊界,就把邊界的高度都設定到最高值
#include<iostream>
using namespace std;
#define MaxN 105

int map[MaxN][MaxN], R, C;
int dis[MaxN][MaxN];

int DFS(int x,int y){
  if(dis[x][y]==-1){ // -1代表沒走過
    dis[x][y]=0; // 過程中先把dis[x][y]標記成0代表走過,也可以避免相等時往回走
    int path=0;
    if(map[x][y]>map[x-1][y]) path=max(path,DFS(x-1,y));
    if(map[x][y]>map[x][y-1]) path=max(path,DFS(x,y-1));
    if(map[x][y]>map[x+1][y]) path=max(path,DFS(x+1,y));
    if(map[x][y]>map[x][y+1]) path=max(path,DFS(x,y+1));
    dis[x][y]=path+1;
  }
  return dis[x][y];
}
int main(){
  string ss;
  int T, maxDis;
  //設定左上邊界
  for(int i=0;i<MaxN;i++)
    map[i][0]=map[0][1]=MaxN;

  cin>>T;
  while(T--){
    cin>>ss>>R>>C;
    for(int i=1;i<=R;i++){
      for(int j=1;j<=C;j++)
        cin>>map[i][j], dis[i][j]=-1;
      map[i][C+1]=MaxN;
    }
    //設定下邊界
    for(int i=1;i<=C;i++)
      map[R+1][i]=MaxN;

    maxDis=0;
    for(int i=1;i<=R;i++)
      for(int j=1;j<=C;j++)
        if(dis[i][j]==-1)
          maxDis=max(maxDis,DFS(i,j));
    cout<<ss<<": "<<maxDis<<endl;
  }
}