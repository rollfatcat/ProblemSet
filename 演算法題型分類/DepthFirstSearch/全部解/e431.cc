/* 枚舉可以經過所有點的方法數(起終點的路線顛倒的話只能算一種) */
#include<bits/stdc++.h>
using namespace std;
 
int R, C, end_DFS, cnt;
bool vis[7][7]={};
void DFS(int x,int y,int num){
	if(num==end_DFS){ cnt++; return; }
	vis[x][y]=1;
	if(x>1 and vis[x-1][y]==0) DFS(x-1,y,num+1);
	if(x<R and vis[x+1][y]==0) DFS(x+1,y,num+1);
	if(y>1 and vis[x][y-1]==0) DFS(x,y-1,num+1);
	if(y<C and vis[x][y+1]==0) DFS(x,y+1,num+1);
	vis[x][y]=0;
}
int main(){
	while(scanf("%d %d",&R,&C)==2){
		// init
		end_DFS=R*C;
		cnt=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				DFS(i,j,1);
		printf("%d\n",cnt>>1);
	}
}
