// 注意測資：11 5 2，要輸出：8 1

#include<iostream>
using namespace std;

int main(){
  int T, X, Y;
  while(scanf("%d%d%d",&T,&X,&Y)==3){
    int obj_monster=(T-Y)/X;
    if(T%X<Y) T-=T%X;
    int sub_monster=T-obj_monster*Y;
    printf("%d %d\n",sub_monster,obj_monster);
  }
}