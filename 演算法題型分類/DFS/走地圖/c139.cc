// 簡單DFS走地圖，單位是edge，走過的邊雙向要設定成0
#include<iostream>
using namespace std;

int node[9];
bool edgeMap[5][5]={
  {1,0,0,1,0},
  {0,1,0,1,0},
  {0,0,1,0,0},
  {1,1,0,1,0},
  {0,0,0,0,1}
};
void DFS(int n){
  if(n==9){
    for(int i=0;i<9;i++)
      cout<<node[i]+1;
    cout<<endl;
    return;
  }
  for(int i=0;i<5;i++)
    if(!edgeMap[ node[n] ][i]){
      node[n]=i;
      edgeMap[ node[n] ][i]=edgeMap[i][ node[n] ]=1;
      DFS(n+1);
      edgeMap[ node[n] ][i]=edgeMap[i][ node[n] ]=0;
    }
}
int main(){
  node[0]=0,  DFS(1);
}