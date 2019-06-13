// 二維座標的判斷和利用陣列描述『周圍』的格子
#include<bits/stdc++.h>
using namespace std;

int neighbor[9][4]={ {-1,-1, 1, 3}, {-1, 0, 2, 4}, {-1, 1, 5,-1},
                     { 0,-1, 4, 6}, { 1, 3, 5, 7}, { 2, 4, 8,-1},
                     { 3,-1,-1, 7}, { 4, 6,-1, 8}, { 5, 7,-1,-1}};
int main(){
  int caseT, x, y, z;
  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d %d",&x,&y,&z);
    x--, y--, z--;
    vector<bool> color(9,false);
    color[y]=color[z]=1;
    for(int i=0;i<4;i++)
      if(neighbor[y][i]>=0)
        color[ neighbor[y][i] ]=1;
    for(int i=0;i<4;i++)
      if(neighbor[z][i]>=0)
        color[ neighbor[z][i] ]=1;
    bool empty=true;
    for(int i=0;i<4;i++)
      if(neighbor[x][i]>=0 and color[ neighbor[x][i] ]==0)
        printf("%d ",neighbor[x][i]+1), empty=false;
    puts((empty)?"Empty":"");
  }
}