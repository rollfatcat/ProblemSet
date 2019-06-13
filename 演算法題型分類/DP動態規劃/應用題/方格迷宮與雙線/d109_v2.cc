// 參考：https://blog.csdn.net/yinghui_yht/article/details/79672893?utm_source=blogxgwz4
// 因为两个人到目的地的步数相同，所以枚举步数和两个人的横坐标之后，就可以算出两个人纵坐标
// 這個做法的問題在於 x1,y1,x2,y2 必須落在合理的範圍內, 但好處是這種狀態的描述可以只描述組合(非排列)
// 時間從 88ms=>0ms
#include<iostream>
#include<cstring>
using namespace std;

int R, C, map[51][51];
int dis[101][51][51];
int MaxNum(int a, int b, int c, int d){ return max(max(a,b),max(c,d)); }
int main(){
  int x1, x2, y1, y2, Cmin;

  while(cin>>R>>C){
    for(int i=1;i<=R;i++)
      for(int j=1;j<=C;j++)
        cin>>map[i][j];
    memset(dis,0,sizeof(dis));
    //只往外走一步時,只存在唯一選項
    dis[3][1][2]=map[1][2]+map[2][1];
    for(int step=4;step<R+C;step++){ //窮舉全部的步數
      Cmin=(C>step)?step:C; //y座標的範圍落在(1,C)
      for(y1=1;y1<=Cmin;y1++){
        for(x1=step-y1; x1>R; y1++,x1--);  //x座標的範圍落在(1,R)
        for(y2=y1+1;y2<=Cmin;y2++){ //避免路徑出現交叉 y2從 y1+1开始
          for(x2=step-y2; x2>R; y2++,x2--);
          dis[step][y1][y2]=MaxNum(dis[step-1][y1][y2],
                                   dis[step-1][y1-1][y2],
                                   dis[step-1][y1][y2-1],
                                   dis[step-1][y1-1][y2-1])+map[x1][y1]+map[x2][y2];
        }
      }
    }
    // 路徑上的點不能相交,所以DP的最大狀態就是算到 x+y=R+C-1 的線段方程式, 且只有一種組合(y1,y2)
    cout<<dis[R+C-1][C-1][C]<<endl;
  }
}
/*
3 3
0 3 9
2 8 5
5 7 0
3 3
0 2 5
3 8 7
9 5 0
*/