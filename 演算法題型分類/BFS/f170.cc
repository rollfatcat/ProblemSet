/* 給定邊長Ｎ、起點和座標Ｎ×Ｎ地圖上每個格子的高度，輸出最多可以走到的格子數？
 * 移動到相鄰格子的條件：兩格的高度落差不超過２
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
int  hgt[MaxN][MaxN];
bool vis[MaxN][MaxN];
struct NODE{
	int x, y;
	NODE(int x=0,int y=0):x(x),y(y){}
} start, now;
int main(){
	int N, ans=0;
	scanf("%d\n%d %d\n",&N,&start.x,&start.y);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			scanf("%d",&hgt[i][j]), 
			vis[i][j]=0;
	queue<NODE> Q;
	Q.push(start);
	while(Q.empty()==0){
		now=Q.front(); Q.pop();
		if(vis[now.x][now.y]) continue;
		vis[now.x][now.y]=1;
		ans++;
		if(now.x>0 and vis[now.x-1][now.y]==0 and abs(hgt[now.x][now.y]-hgt[now.x-1][now.y])<=2)
			Q.push(NODE(now.x-1,now.y));
		if(now.y>0 and vis[now.x][now.y-1]==0 and abs(hgt[now.x][now.y]-hgt[now.x][now.y-1])<=2)
			Q.push(NODE(now.x,now.y-1));
		if(now.x+1<N and vis[now.x+1][now.y]==0 and abs(hgt[now.x][now.y]-hgt[now.x+1][now.y])<=2)
			Q.push(NODE(now.x+1,now.y));
		if(now.y+1<N and vis[now.x][now.y+1]==0 and abs(hgt[now.x][now.y]-hgt[now.x][now.y+1])<=2)
			Q.push(NODE(now.x,now.y+1));
	}
	printf("%d\n",ans);
}

