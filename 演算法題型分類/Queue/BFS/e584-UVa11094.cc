/* 需要找到除了自己所在的大陸以外最大區域
 * 相鄰的定義：周圍4格
   大陸是一組相連的陸地區域，被水域或地圖末端完全包圍。如果兩個區域具有共同的邊緣，則代表它們彼此相連。
 *  邊界判定：
   由於地球是圓柱，所以地圖最左區域(x, 0)和最右區域(x, N-1)相連。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20+1;
const int MaxM=20;
int N, M;
char mch[MaxN][MaxM];
bool wat[MaxN][MaxM];
struct NODE{
	int x, y;
	NODE(int nx=0,int ny=0):x(nx),y(ny){}
} king, now;

inline int BFS(NODE st,int cnt=0){
	queue<NODE>Q;
	Q.push(st);
	while(Q.empty()==0){
		now=Q.front(); Q.pop();
		if(wat[now.x][now.y]==0)
			continue;
		cnt++;
		wat[now.x][now.y]=0;
		if(now.x-1>=0 and wat[now.x-1][now.y])
			Q.push(NODE(now.x-1,now.y));
		if(now.x+1< M and wat[now.x+1][now.y])
			Q.push(NODE(now.x+1,now.y));
		if(now.y-1>=0 and wat[now.x][now.y-1])
			Q.push(NODE(now.x,now.y-1));
		else if(now.y==0 and wat[now.x][N-1])
			Q.push(NODE(now.x,N-1));
		if(now.y+1< N and wat[now.x][now.y+1])
			Q.push(NODE(now.x,now.y+1));
		else if(now.y==N-1 and wat[now.x][0])
			Q.push(NODE(now.x,0));
	}
	return cnt;
}
int main(){
	while(scanf("%d %d\n",&M,&N)==2){
		for(int i=0;i<M;i++)
			scanf("%s\n",mch[i]);
		scanf("%d %d\n",&king.x,&king.y);
		// 地形只有兩種：陸/水，且保證王所在的格子一定是陸
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				wat[i][j]=mch[i][j]==mch[king.x][king.y];
		// BFS
		BFS(king);
		int Maxcnt=0;
		for(int i=0;i<M;i++)
			for(int j=0;j<N;j++)
				if(wat[i][j])
					Maxcnt=max(Maxcnt,BFS(NODE(i,j)));
		printf("%d\n",Maxcnt);
	}
}