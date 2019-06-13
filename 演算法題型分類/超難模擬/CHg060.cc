// 模擬題，DFS填方塊的複雜版本
// 避免無窮遞迴的狀態喔(展開前先判斷全部方塊是不是都已經屬於同一位玩家)

#include<iostream>
#include<iomanip>
using namespace std;
#define MaxLen 11

int R, C, T, r, c;
int gridNum[2], rxc;
string Player[2]={"GREEN","BLUE"};
struct Grid{
  int num,who;
}map[MaxLen][MaxLen];
int neighborNum[MaxLen][MaxLen];
int move_r[4]={-1,1,0,0};
int move_c[4]={0,0,-1,1};

int CountNeighbor(int r, int c){ return 4-(r==1 or r==R)-( c==1 or c==C); }
void ShowMap(){
  for(int i=1;i<=R;i++){
    for(int j=1;j<=C;j++)
      cout<<setw(2)<<map[i][j].num<<' ';
    cout<<endl;
  }
}

void DFS(int r, int c, int who){
  map[r][c].num+=1;
  if(map[r][c].who==-1){
    map[r][c].who=who;
    gridNum[who]++;
    return;
  }
  if(map[r][c].who!=who){
    gridNum[map[r][c].who]--;
    gridNum[who]++;
    map[r][c].who=who;
  }
  if(gridNum[0]==rxc or gridNum[1]==rxc)
    return;
  if(map[r][c].num>neighborNum[r][c]){
    map[r][c].num-=neighborNum[r][c];
    for(int i=0;i<4;i++){
      int new_r=r+move_r[i];
      int new_c=c+move_c[i];
      if(0<new_c and new_c<=C and 0<new_r and new_r<=R)
        DFS(new_r,new_c,who);
    }
  }
}

int main(){
  while(cin>>R>>C>>T and R){
    gridNum[0]=gridNum[1]=0;
    rxc=R*C;
    for(int i=1;i<=R;i++){
      for(int j=1;j<=C;j++){
        map[i][j].num=1;
        map[i][j].who=-1;
        neighborNum[i][j]=CountNeighbor(i,j);
      }
    }
    for(int turn=0;turn<T;turn++){
      cin>>r>>c;
      DFS(r,c,turn%2);
    }
    //輸出
    string msg=(gridNum[0]==rxc)?"GREEN":( (gridNum[1]==rxc)?"BLUE":"processing" );
    cout<<gridNum[0]<<' '<<gridNum[1]<<' '<<msg<<endl;
  }
}