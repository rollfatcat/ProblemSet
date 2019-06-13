// 題目給予一張踩地雷的地圖('*'=地雷 '?'=空地)
// 輸出踩地雷的數字圖(那格如果是地雷就輸出'*'否則就是周圍有幾個地雷的數量)

#include<bits/stdc++.h>
using namespace std;

int mvx[8]={-1,-1,-1, 0, 0, 1, 1, 1};
int mvy[8]={-1, 0, 1,-1, 1,-1, 0, 1};
int cnt[101][101];
char ss[101][101];
int main(){
  int R, C;
  while(scanf("%d%d",&R,&C)!=EOF){
    for(int i=0;i<R;i++)
      scanf("%s",ss[i]);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        if(ss[i][j]=='*')
          for(int k=0;k<8;k++){
            int x=i+mvx[k];
            int y=j+mvy[k];
            if(0<=x and x<R and 0<=y and y<C)
              cnt[x][y]++;
          }
    for(int i=0;i<R;i++,putchar('\n'))
      for(int j=0;j<C;j++)
        putchar( (ss[i][j]=='*')?'*': cnt[i][j]+'0');
  }
}