// 參考：https://blog.csdn.net/GailyYelp/article/details/62054337?utm_source=blogxgwz9
// 找兩條互不相交的路徑可以從左上到達右下的路徑(雙線DP)
#include<iostream>
#include<cstring>
using namespace std;

int R, C, map[51][51];
//dis[x1][y1][x2][y2]表示第一个传到的地方(x1,y1)和第二个人传到的地方(x2,y2)的路径的和
int dis[51][51][51][51];
int MaxNum(int a, int b, int c, int d){ if(b>a) a=b;  if(c>a) a=c;  return (d>a)?d:a; }
int main(){

  while(cin>>R>>C){
    for(int i=1;i<=R;i++)
      for(int j=1;j<=C;j++)
        cin>>map[i][j];
    memset(dis,0,sizeof(dis));
    for(int x1=1;x1<=R;x1++)
      for(int y1=1;y1<=C;y1++)
        for(int x2=1;x2<=R;x2++) // v2版本的 x2可以從x1開始是因為他的狀態不是窮舉所有座標組合
          for(int y2=1;y2<=C;y2++){ //同時讓兩條路徑一起走
            dis[x1][y1][x2][y2]=MaxNum(dis[x1-1][y1][x2-1][y2],
                                       dis[x1-1][y1][x2][y2-1],
                                       dis[x1][y1-1][x2-1][y2],
                                       dis[x1][y1-1][x2][y2-1])+map[x1][y1]+map[x2][y2];
            //当x1==x2时，说明两个人相交了，因为每个同学只能传递一次，所以这里应该减去一个人在此的路程
            if(x1==x2 and y1==y2)
              dis[x1][y1][x2][y2]-=map[x1][y1];
          }
    cout<<dis[R][C][R][C]<<endl;
  }
}