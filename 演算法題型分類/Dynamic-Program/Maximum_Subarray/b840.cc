// 二維版本的(矩形)區間和最大化
// 前綴和＋暴力法：枚舉起點和終點(四維)
// 三維版本：利用動態規劃的作法，針對Column，枚舉任兩個Row間的區間和做區間和最大化

#include<iostream>
#include<cstring>
using namespace std;

int main(){
  int N, map[21][21];
  while(cin>>N){
    memset(map,0,sizeof(map));
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        cin>>map[i][j];
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        map[i][j]+=map[i-1][j];
    for(int i=1;i<=N;i++)
      for(int j=1;j<=N;j++)
        map[i][j]+=map[i][j-1];
    int MaxV=0;
    for(int lx=0;lx<N;lx++)
      for(int ly=0;ly<N;ly++)
        for(int rx=lx+1;rx<=N;rx++)
          for(int ry=ly+1;ry<=N;ry++){
            int tmpV=map[rx][ry]+map[lx][ly]-map[lx][ry]-map[rx][ly];
            MaxV=(MaxV>tmpV)?MaxV:tmpV;
          }
    cout<<MaxV<<endl;
  }
}