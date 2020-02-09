// Pair數量不大可以簡單暴力法
// 可以對照 a638 Pair數量極大時就不能暴力

#include<iostream>
#include<cmath>
using namespace std;

struct nn{ int x, y; } Node[20];
int main(){
  for(int m,n; cin>>n>>m;){
    int minD=n*n;
    for(int i=0;i<m;i++){
      cin>>Node[i].x>>Node[i].y;
      for(int j=0;j<i;j++){
        int tmpD=(Node[i].x-Node[j].x)*(Node[i].x-Node[j].x)+(Node[i].y-Node[j].y)*(Node[i].y-Node[j].y);
        if(minD>tmpD)
          minD=tmpD;
      }
    }
    printf("%.4lf\n",sqrt(minD));
  }
}