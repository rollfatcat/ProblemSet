/* 輸出相同連續高度的最大面積，當面積小於2時則輸出0
 * 題目保證輸入的高度介於(1,9)，地圖最大是30x30
 */

#include<bits/stdc++.h>
using namespace std;
#define MAXN 31

struct NODE{ int x, y; };
int main(){
  int R, C, Q;
  int H[MAXN][MAXN];
  bool vis[MAXN][MAXN];
  while(cin>>R>>C){
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        cin>>H[i][j],
        vis[i][j]=0;
    // 利用 Stack 完成DFS
    vector<int> max_area(10,0);
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++)
        if(!vis[i][j]){
          int now_area=0;
          int nowH=H[i][j];
          stack<NODE> S;
          S.push({i,j});
          while(S.empty()==0){
            NODE now=S.top(); S.pop();
            if(vis[now.x][now.y]) continue;
            vis[now.x][now.y]=1;
            now_area++;
            if(now.x>0 and vis[now.x-1][now.y]==0 and H[now.x-1][now.y]==nowH) S.push({now.x-1,now.y});
            if(now.y>0 and vis[now.x][now.y-1]==0 and H[now.x][now.y-1]==nowH) S.push({now.x,now.y-1});
            if(now.x<R-1 and vis[now.x+1][now.y]==0 and H[now.x+1][now.y]==nowH) S.push({now.x+1,now.y});
            if(now.y<C-1 and vis[now.x][now.y+1]==0 and H[now.x][now.y+1]==nowH) S.push({now.x,now.y+1});
          }
          if(now_area>1)
            max_area[nowH]=max(max_area[nowH],now_area);
        }
    // 根據輸入的高度輸出最大面積
    int nowH;
    cin>>Q;
    while(Q--)
      cin>>nowH,
      cout<<max_area[nowH]<<'\n';
  }
}