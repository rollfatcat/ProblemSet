// Try & Error
// 找規律：(1 1)(2 2 2 2)( 3 3 3 3 3 3) 4 4 4 4

#include<iostream>
using namespace std;

int map[49][49];
int len;
int move_y[4]={ -1, 0, 1, 0};
int move_x[4]={ 0, -1, 0, 1};
bool isIn(int x, int y){ return 0<=x and x<len and 0<=y and y<len;}
int main(void){
  int dir;
  while(cin>>len){
    // input
    cin>>dir;
    for(int i=0;i<len;i++)
      for(int j=0;j<len;j++)
        cin>>map[i][j];
    // output
    int pos_x=len/2;
    int pos_y=len/2;
    cout<<map[pos_x][pos_y];
    int step;
    for(step=1; step<len; step++){
      for(int i=1;i<=step;i++){
        pos_x += move_x[dir];
        pos_y += move_y[dir];
        cout<<map[pos_x][pos_y];
      }
      dir=(dir+1)%4;
      for(int i=1;i<=step;i++){
        pos_x += move_x[dir];
        pos_y += move_y[dir];
        cout<<map[pos_x][pos_y];
      }
      dir=(dir+1)%4;
    }
    for(int i=1;i<step;i++){
      pos_x += move_x[dir];
      pos_y += move_y[dir];
      cout<<map[pos_x][pos_y];
    }
    cout<<endl;
  }
}
