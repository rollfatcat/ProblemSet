#include<iostream>
using namespace std;
#define MaxNum 500

int T, N, M, node_cnt;
int map[MaxNum][MaxNum];
bool isIn(int x, int y){ return 0<=x and x<M and 0<=y and y<N; }
int pos_x[MaxNum*MaxNum], pos_y[MaxNum*MaxNum];
int mvx[4]={0,0,-1,1};
int mvy[4]={-1,1,0,0};
int main(void){
  string ss;
  cin>>T;
  while(T--){
    cin>>N>>M;
    node_cnt=0;
    for(int i=0;i<N;i++){
      cin>>ss;
      for(int j=0;j<M;j++){
        map[i][j]=(ss[j]=='1');
        if(map[i][j])
          pos_y[node_cnt]=i, pos_x[node_cnt++]=j;
      }
    }
    //
    int total=0;
    for(int i=0;i<node_cnt;i++)
      for(int j=0;j<4;j++){
        int x=pos_x[i]+mvx[j];
        int y=pos_y[i]+mvy[j];
        total+= (isIn(x,y))?(map[y][x]^1):1 ;
      }
    cout<<total<<endl;
  }
}