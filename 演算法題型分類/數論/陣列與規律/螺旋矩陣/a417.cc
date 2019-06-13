// 螺旋規律放陣列，同APCS c292的題目
#include<iostream>
using namespace std;

int main(){
  int T, N, C;
  int matrix[101][101];
  int move_x[4]={ -1, 0, 1, 0};
  int move_y[4]={ 0, 1, 0, -1};

  for(cin>>T; T--; ){
    cin>>N>>C;
    int pos_x=1, pos_y=1, num=2;
    int dir=(C==1)?1:2, inc=(C==1)?1:-1;
    matrix[1][1]=1;
    for(int i=2;i<=N;i++)
      pos_x+=move_x[dir],
      pos_y+=move_y[dir],
      matrix[pos_x][pos_y]=num++;
    for(int step=N-1;step>=1;step--){
      dir=(dir+inc+4)%4;
      for(int i=1;i<=step;i++)
        pos_x+=move_x[dir],
        pos_y+=move_y[dir],
        matrix[pos_x][pos_y]=num++;
      dir=(dir+inc+4)%4;
      for(int i=1;i<=step;i++)
        pos_x+=move_x[dir],
        pos_y+=move_y[dir],
        matrix[pos_x][pos_y]=num++;
    }
    for(int i=1;i<=N;i++,printf("\n"))
      for(int j=1;j<=N;j++)
        printf("%5d",matrix[i][j]);
  }
}