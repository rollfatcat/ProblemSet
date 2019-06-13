// 判斷正長方形(邊皆垂直於座標軸)和圓型的相交的情況
// 作法 : 窮舉所有可能, 4點在外面邊卻割圓+ 4個頂點在圓內
#include<iostream>
using namespace std;
#define MaxN 100000

struct Rect{ double x,y,w,h; }rect[MaxN];
double CountDis(double x1, double y1, double x2, double y2){
  return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main(){
  int caseNum, n, cnt;
  double circle_x, circle_y, circle_r;

  cin>>caseNum;
  while(caseNum--){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%lf %lf %lf %lf",&rect[i].x,&rect[i].y,&rect[i].h,&rect[i].w);
    scanf("%lf %lf %lf",&circle_x,&circle_y,&circle_r);
    cnt=0;
    for(int i=0;i<n;i++){
      double lx=rect[i].x-rect[i].h/2;
      double rx=rect[i].x+rect[i].h/2;
      double ly=rect[i].y-rect[i].w/2;
      double ry=rect[i].y+rect[i].w/2;

      // 4點在外邊卻割圓
      if( lx<=(circle_x+circle_r) and (circle_x-circle_r)<=rx and ly<=circle_y and circle_y<=ry )  cnt++;
      else if( lx<=circle_x and circle_x<=rx and ly<=(circle_y+circle_r) and (circle_y-circle_r)<=ry )  cnt++;
      // 以下是4頂點落在圓內的判斷
      else if(CountDis(lx,ly,circle_x,circle_y)<=(circle_r*circle_r))  cnt++;
      else if(CountDis(lx,ry,circle_x,circle_y)<=(circle_r*circle_r))  cnt++;
      else if(CountDis(rx,ly,circle_x,circle_y)<=(circle_r*circle_r))  cnt++;
      else if(CountDis(rx,ry,circle_x,circle_y)<=(circle_r*circle_r))  cnt++;
    }
    cout<<cnt<<endl;
  }
}

/*
2
3
0.0 0.0 1.0 1.0
0.0 3.0 1.0 1.0
3.0 0.0 1.0 1.0
1.0 1.0 1.0
3
0.0 0.0 1.0 1.0
0.0 3.0 1.0 1.0
3.0 0.0 1.0 1.0
1.0 1.0 2.0
*/