//  基礎struct練習
#include<bits/stdc++.h>
using namespace std;

struct RECT{
  int L, D, R, U, area;
  bool insect(int x,int y){ return L<=x and x<=R and D<=y and y<=U; }
}rect[30];
int main(){
  for(int N,Q; scanf("%d %d",&N,&Q)==2;){
    for(int i=0;i<N;i++){
      scanf("%d %d %d %d",&rect[i].L,&rect[i].D,&rect[i].R,&rect[i].U);
      if(rect[i].L>rect[i].R) swap(rect[i].L,rect[i].R);
      if(rect[i].D>rect[i].U) swap(rect[i].D,rect[i].U);
      rect[i].area=(rect[i].R-rect[i].L)*(rect[i].U-rect[i].D);
    }
    for(long sumN=0,x,y; Q--; sumN=0){
      scanf("%d %d",&x,&y);
      for(int i=0;i<N;i++)
        if(rect[i].insect(x,y))
          sumN+=rect[i].area;
      printf("%ld\n",sumN);
    }
  }
}