// 2146113925<0x7fffffff
#include<iostream>
#include<cstring>
using namespace std;

int money[5]={1,5,10,25,50};
int map[5][7490];
int TD(int n,int w){
  if(map[n][w]==0)
    if((w<money[n]))
      map[n][w]=TD(n-1,w);
    else
      map[n][w]=TD(n-1,w)+TD(n,w-money[n]);
  return map[n][w];
}
int main(){
  // 方法數至少1種, 0可以代表沒有拜訪過
  memset(map,0,sizeof(map));
  // boundary
  for(int i=0;i<7490;i++)
    map[0][i]=1;
  for(int i=1;i<5;i++)
    map[i][0]=1;
  int w;
  while(cin>>w)
    cout<<TD(4,w)<<endl;
}