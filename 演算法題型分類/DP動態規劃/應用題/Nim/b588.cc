// 不是BFS從(0,0,0)回推狀態...
// 類似 Nim，完成後可以做進階的 a365
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MaxN 101

// DP有3種狀態 : -1=未更新, 0=輸, 1=贏
char DP[MaxN][MaxN][MaxN], status[2]={'l','w'};
bool DFS(int x, int y, int z){
  // Cut-Branch：三堆中個別的數量多少不重要，比如說(3,2,1)=(1,3,2)都可以視為相同的狀態 = (1,2,3)
  int v[3]={x,y,z};
  sort(v,v+3);
  if(DP[x][y][z]==-1){
    DP[x][y][z]=0;
    for(int i=v[0]; i>=1 and DP[x][y][z]==0; i--)
  		DP[x][y][z] |=( !DFS(v[0]-i,v[1],v[2]) | !DFS(v[0]-i,v[1]-i,v[2]) | !DFS(v[0]-i,v[1],v[2]-i) | !DFS(v[0]-i,v[1]-i,v[2]-i) );
  	for(int i=v[1]; i>=1 and DP[x][y][z]==0; i--)
  		DP[x][y][z] |=( !DFS(v[0],v[1]-i,v[2]) | !DFS(v[0],v[1]-i,v[2]-i) );
  	for(int i=v[2]; i>=1 and DP[x][y][z]==0; i--)
  		DP[x][y][z] |= !DFS(v[0],v[1],v[2]-i);
  }
  return DP[x][y][z];
}
int main(){
  memset(DP,0xff,sizeof(DP));
  DP[0][0][0]=0; //沒東西拿＝輸
  //
  int x, y, z;
  while(cin>>x and x)
    cin>>y>>z,
    cout<<status[DFS(x,y,z)]<<endl;
}