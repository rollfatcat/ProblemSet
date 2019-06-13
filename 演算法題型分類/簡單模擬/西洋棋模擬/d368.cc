// 簡單模擬，考驗二維陣列的概念
#include<iostream>
using namespace std;

string ss[8];
char CheckChar[3][5]={ {},{'Q','B','R','N','P'},{'q','b','r','n','p'} };
struct Pos{ int x, y; }king[3], chess;
bool isIn(int x, int y){ return 0<=x and x<8 and 0<=y and y<8; }
int dx[8]={ 0, 1, 1, 1, 0,-1,-1,-1};
int dy[8]={-1,-1, 0, 1, 1, 1, 0,-1};
int CheckDFS(){
  for(int i=1;i<3;i++)
    for(int j=0;j<8;j++){
      chess.x=king[i].x+dx[j],  chess.y=king[i].y+dy[j];
      while( isIn(chess.x,chess.y) and ss[chess.y][chess.x]=='.' )
        chess.x+=dx[j], chess.y+=dy[j];
      if(isIn(chess.x,chess.y) ){
        int t=(j%2)?1:2;
        if( ss[chess.y][chess.x]==CheckChar[i][0] or ss[chess.y][chess.x]==CheckChar[i][t])
          return i;
      }
    }
  return 0;
}
int ndx[8]={ 1, 2, 2, 1,-1,-2,-2,-1};
int ndy[8]={-2,-1, 1, 2, 2, 1,-1,-2};
int CheckKnight(){
  for(int i=1;i<3;i++)
    for(int j=0;j<8;j++){
      chess.x=king[i].x+ndx[j];
      chess.y=king[i].y+ndy[j];
      if( isIn(chess.x,chess.y) and ss[chess.y][chess.x]==CheckChar[i][3] ) return i;
    }
  return CheckDFS();
}
int CheckPawn(){
  for(int i=1;i<3;i++){
    chess.y=king[i].y+((i==1)?1:-1);
    chess.x=king[i].x-1;
    if( isIn(chess.x,chess.y) and ss[chess.y][chess.x]==CheckChar[i][4] ) return i;
    chess.x=king[i].x+1;
    if( isIn(chess.x,chess.y) and ss[chess.y][chess.x]==CheckChar[i][4] ) return i;
  }
  return CheckKnight();
}
int main(){
  string winner[3]={"no","black","white"};
  for(int caseNum=1;true;caseNum++){
    king[1].x=king[1].y=-1;
    king[2].x=king[2].y=-1;
    for(int i=0;i<8;i++){
      cin>>ss[i];
      for(int j=0;j<8;j++)
        if(ss[i][j]=='k') king[1].x=j,  king[1].y=i;      //黑王位置
        else if(ss[i][j]=='K') king[2].x=j,  king[2].y=i; //白王位置
    }
    if(king[1].x==-1 or king[2].x==-1)
      break;
    cout<<"Game #"<<caseNum<<": "<<winner[CheckPawn()]<<" king is in check.\n";
  }
}