/* 題目定義可以『疊加』的定義是底層方塊的底面積必須大於上層的底面積
 * 題目的方塊最多有30個＝180種可能的放置方式(每個方塊透過旋轉可以產生6種不同放置型態)
 * 這個 DP 解法需要"嚴格偏序"才能狀態轉移( 進階版：第一層排序第二層透過BIT維護最大值的作法 )
 */
#include<bits/stdc++.h>
using namespace std;

struct REC{
  int w, h, v;
  REC(int a=0,int b=0,int c=0):w(a),h(b),v(c){}
  bool operator<(const REC &rhs)const{ return(w==rhs.w)? h==rhs.h: w<rhs.w; }
}rec[180];
int DP[180];
int main(){
  int N, x, y, z, tot;
  for(int caseN=1;scanf("%d",&N) and N;caseN++){
    tot=0;
    for(int i=0;i<N;i++)
      scanf("%d%d%d",&x,&y,&z),
      rec[tot++]=REC(x,y,z),
      rec[tot++]=REC(y,x,z),
      rec[tot++]=REC(x,z,y),
      rec[tot++]=REC(z,x,y),
      rec[tot++]=REC(y,z,x),
      rec[tot++]=REC(z,y,x);
    sort(rec,rec+tot);
    int maxh=0;
    for(int i=0;i<tot;i++){
      int nowh=0;
      for(int j=i-1;j>=0;j--)
        if((rec[i].w>rec[j].w and rec[i].h>rec[j].h) or (rec[i].w>rec[j].h and rec[i].h>rec[j].w))
          nowh=max(nowh,DP[j]);
      DP[i]=rec[i].v+nowh;
      maxh=max(maxh,DP[i]);
    }
    printf("Case %d: maximum height = %d\n",caseN,maxh);
  }
}
/*
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0
*/