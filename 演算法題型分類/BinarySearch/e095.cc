#include<bits/stdc++.h>
using namespace std;

const int MAXN=1600;
struct GRID{
  short x,y; int v;
  GRID(int a=0,int b=0,int c=0):x(a),y(b),v(c){}
  bool operator<(const GRID &rhs)const{return v<rhs.v;}
} grids[MAXN*MAXN];
int main(){

  int R, C, x;
  scanf("%d",&R),
  scanf("%d",&C);
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      scanf("%d",&x),
      grids[i*C+j]=GRID(i+1,j+1,x);
  int tot=R*C, Q, tag;
  sort(grids,grids+tot);
  scanf("%d",&Q);
  while(Q--){
    scanf("%d",&tag);
    int nL=0, nR=tot-1, nM;
    while(nL<=nR){
      nM=(nL+nR)>>1;
      if(grids[nM].v==tag){
        printf("yes [%d, %d]\n",grids[nM].x,grids[nM].y); break;
      }else if(grids[nM].v>tag)
        nR=nM-1;
      else
        nL=nM+1;
    }
    if(nL>nR) puts("no");
  }
}