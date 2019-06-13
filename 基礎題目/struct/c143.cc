// 棋盤填格子，輸出塗黑的格子數量
// 練習自訂 struct operator
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 501

int Dir(int x){ return(x>=0)?(x>0):-1; }
struct nn{
  int x,y;
  bool operator==(const nn &other){ return (x==other.x and y==other.y); }
  void operator+(const nn &other){ x+=other.x, y+=other.y; }
}a, b, now, unit;
int main(){
  bool Board[MaxN][MaxN]={};
  int R, C, N, cnt=0;
  cin>>R>>C>>N;
  while(N--){
    cin>>a.x>>a.y>>b.x>>b.y;
    unit={Dir(b.x-a.x), Dir(b.y-a.y)};
    for(now=a; true; now+unit){
      if(!Board[now.x][now.y])
        Board[now.x][now.y]=1, cnt++;
      if(now==b)
        break;
    }
  }
  cout<<cnt<<endl;
}