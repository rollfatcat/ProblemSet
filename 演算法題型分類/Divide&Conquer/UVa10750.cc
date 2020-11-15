// 類似 a638，只是輸出點對的中點座標(這題有多組姐的情況 ubug 答案不一定對)
// 中文題目：http://unfortunatedog.blogspot.com/2013/07/10750-beautiful-points.html
// 剪枝：Ｘ維度已經排序，所以單算Ｘ的距離差距大於最小值時就不需要繼續比對
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000;
const int INF=1<<30;
int mndist;
double recx, recy;
struct POINT{
  int x, y;
  bool operator<(const POINT &rhs)const{ return (x==rhs.x)?(y<rhs.y):(x<rhs.x); }
}node[MAXN];

inline int NodeDis(int a,int b){ return (node[a].x-node[b].x)*(node[a].x-node[b].x)+(node[a].y-node[b].y)*(node[a].y-node[b].y);}
void CDQ(int nL,int nR){
  if(nL==nR) return; // 分化到剩下一點時無法湊出配對
  int nM=(nL+nR)>>1;
  CDQ(  nL,nM);
  CDQ(nM+1,nR);
  // merge
  for(int iL=nM; iL>=nL; iL--){
    if((node[iL].x-node[nM].x)*(node[iL].x-node[nM].x)>=mndist) break;  // <-剪枝
    for(int iR=nM+1; iR<=nR; iR++){
      if((node[iL].x-node[iR].x)*(node[iL].x-node[iR].x)>=mndist) break;// <-剪枝
      int v=NodeDis(iL,iR);
      if(v<mndist){
        mndist=v;
        recx=(node[iL].x+node[iR].x)/2.0;
        recy=(node[iL].y+node[iR].y)/2.0;
      }
    }
  }
}
int main(){
  int caseT, N;
  scanf("%d",&caseT);
  for(int caseN=0;caseN<caseT;caseN++){
    scanf("%d",&N);
    for(int i=0;i<N;i++)
      scanf("%d",&node[i].x),
      scanf("%d",&node[i].y);
    sort(node,node+N);
    //
    mndist=INF;
    CDQ(0,N-1);
    //
    if(caseN) puts("");
    printf("%.3lf %.3lf\n",recx,recy);
  }
}
/*
2
4
3 9
8 11
12 5
12 14

8
4 5
4 16
5 1
6 7
8 18
11 20
16 14
20 18
*/