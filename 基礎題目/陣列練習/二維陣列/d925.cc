// 注意 1xM 和 Nx1 和 1x1 的情況
#include<iostream>
using namespace std;

int main(){

  for(int N,M,T; scanf("%d %d %d",&N,&M,&T)!=EOF ;){
    double h=0.0;
    if(N>1 and M>1)
      for(int x,y,k; T--;){
        scanf("%d %d %d",&x,&y,&k);
        bool eX=(x==1 or x==N), eY=(y==1 or y==M);
        if(eX and eY)
          h+=(k<<1);
        else if(eX or eY)
          h+=(k<<2);
        else
          h+=(k<<2)+(k<<1)+k;
      }
    else if(N==1 and M>1)
      for(int x,y,k; T--;){
        scanf("%d %d %d",&x,&y,&k);
        if(1<y and y<M)
          h+=k;
      }
    else if(M==1 and N>1)
      for(int x,y,k; T--;){
        scanf("%d %d %d",&x,&y,&k);
        if(1<x and x<N)
          h+=k;
      }
    else
      for(int x,y,k; T--;)
        scanf("%d %d %d",&x,&y,&k), h-=k;
    printf("%.2lf\n",h/(N*M));
  }
}