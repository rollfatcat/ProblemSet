// 題目沒有告知座標的範圍(事後證明可以用int存取)，也未保證計算面積時數值都在int上限內
// 注意計算過程中的溢位問題(或是統一改為double計算較為安全)
// 能夠構成最大面積三角形的點一定落在『外圍』=> 凸包(3ms)

#include<bits/stdc++.h>
using namespace std;
#define MAXN 205

struct NODE{
  double x, y;
  NODE(int in_x=0,int in_y=0):x(in_x),y(in_y){}
  bool operator<(const NODE &rhs)const{ return x<rhs.x or x==rhs.x and y<rhs.y; }
} node[MAXN], CH_L[MAXN], CH_U[MAXN];

inline double cross(NODE &a,NODE &b,NODE &o){ return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x); }
inline int Monotone_Chain(int N,int L=0,int U=0){
  sort(node,node+N);
  for(int i=0;i<N;i++){
    while(L>=2 and cross(CH_L[L-2],CH_L[L-1],node[i])<=0.0) L--;
    while(U>=2 and cross(CH_U[U-2],CH_U[U-1],node[i])>=0.0) U--;
    CH_L[L++]=node[i];
    CH_U[U++]=node[i];
  }
  // 把上半部的部分複製到下半部的陣列後面(兩個起終點是相同的)
  for(--U;U;)
    CH_L[L++]=CH_U[--U];
  return L;
}
int main(){
  int N, x, y;
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d%d",&x,&y),
      node[i]=NODE(x,y);
    N=Monotone_Chain(N);
    double max_area=0.0, now_area;
    for(int a=0;a<N;a++)
      for(int b=a+1;b<N;b++)
        for(int c=b+1;c<N;c++){
          now_area =CH_L[a].x*CH_L[b].y+CH_L[b].x*CH_L[c].y+CH_L[c].x*CH_L[a].y;
          now_area-=CH_L[a].x*CH_L[c].y+CH_L[b].x*CH_L[a].y+CH_L[c].x*CH_L[b].y;
          now_area*=0.5;
          if(now_area<0.0) now_area=-now_area;
          max_area=max(max_area,now_area);
        }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<max_area<<endl;
  }
}