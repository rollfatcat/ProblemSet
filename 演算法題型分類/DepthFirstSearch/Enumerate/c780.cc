/* 給定Ｒ×Ｃ的棋盤( 保證格子數 ≦ 40 )，輸出根據規則最多能攻擊到卒的個數？
 * 規則：一開始炮位於棋盤左上角，炮必須隔著一個障礙物攻擊到下個的"卒"
 * 解題關鍵：BruteForce
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=8;
bool vis[MaxN][MaxN]={1};
int R, C, ans=0;
 
void DFS(int x,int y,int cnt){
 	ans=max(ans,cnt);
 
 	int tx, ty;
 	if(x>1){
 		for(tx=x-1;tx>=0 and vis[tx][y]; tx--);
 		for(tx-=1 ;tx>=0 and vis[tx][y]; tx--);
 		if(tx>=0){
 			vis[tx][y]=1;
 			DFS(tx,y,cnt+1);
 			vis[tx][y]=0;
 		}
 	}
 	if(x<R-2){
 		for(tx=x+1;tx<R and vis[tx][y]; tx++);
 		for(tx+=1 ;tx<R and vis[tx][y]; tx++);
 		if(tx<R){
 			vis[tx][y]=1;
 			DFS(tx,y,cnt+1);
 			vis[tx][y]=0;
 		}
 	}
 	if(y>1){
 		for(ty=y-1;ty>=0 and vis[x][ty]; ty--);
 		for(ty-=1 ;ty>=0 and vis[x][ty]; ty--);
 		if(ty>=0){
 			vis[x][ty]=1;
 			DFS(x,ty,cnt+1);
 			vis[x][ty]=0;
 		}
 	}
 	if(y<C-2){
 		for(ty=y+1;ty<C and vis[x][ty]; ty++);
 		for(ty+=1 ;ty<C and vis[x][ty]; ty++);
 		if(ty<C){
 			vis[x][ty]=1;
 			DFS(x,ty,cnt+1);
 			vis[x][ty]=0;
 		}
 	}
}
int main(){
	scanf("%d %d\n",&R,&C);
	DFS(0,0,0);
	printf("%d\n",ans);
	
}