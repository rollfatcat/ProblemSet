// 題目沒有告知座標的範圍(事後證明可以用int存取)，也未保證計算面積時數值都在int上限內
// 注意計算過程中的溢位問題(或是統一改為double計算較為安全)
// 暴力法枚舉三個點，構成三角形之後求最大面積(9ms)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 205

struct NODE{
  int x, y;
  NODE(int in_x=0,int in_y=0):x(in_x),y(in_y){}
} node[MAXN];
int main(){
  int N, x, y;
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d%d",&x,&y),
      node[i]=NODE(x,y);
    double max_area=0.0, now_area;
    for(int a=0;a<N;a++)
      for(int b=a+1;b<N;b++)
        for(int c=b+1;c<N;c++){
          now_area =(long)node[a].x*node[b].y+(long)node[b].x*node[c].y+(long)node[c].x*node[a].y;
          now_area-=(long)node[a].x*node[c].y+(long)node[b].x*node[a].y+(long)node[c].x*node[b].y;
          now_area*=0.5;
          if(now_area<0.0) now_area=-now_area;
          max_area=max(max_area,now_area);
        }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<max_area<<endl;
  }
}