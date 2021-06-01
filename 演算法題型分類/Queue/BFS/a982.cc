// Queue
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 100

int step[MaxN][MaxN];
bool map[MaxN][MaxN];
int move_x[4]={0,0,-1,1};
int move_y[4]={-1,1,0,0};
struct pos{ int x,y; }tmp,ed;
int main(){
  string ss;
  int N;

  cin>>N;
  ed={N-2,N-2};
  for(int i=0;i<N;i++){
    cin>>ss;
    for(int j=0;j<N;j++)
      map[i][j]=(ss[j]=='.'),
      step[i][j]=MaxN;
  }
  queue<pos>Q;
  Q.push({1,1});
  step[1][1]=1;
  while(!Q.empty() and step[ed.x][ed.y]==MaxN){
    tmp=Q.front();
    Q.pop();
    for(int i=0;i<4;i++){
      int x=tmp.x+move_x[i];
      int y=tmp.y+move_y[i];
      if(map[x][y] and step[x][y]==MaxN){
        step[x][y]=step[tmp.x][tmp.y]+1;
        Q.push({x,y});
      }
    }
  }
  ss=(step[ed.x][ed.y]==MaxN)?"No solution!": to_string(step[ed.x][ed.y]);
  cout<<ss<<endl;
}