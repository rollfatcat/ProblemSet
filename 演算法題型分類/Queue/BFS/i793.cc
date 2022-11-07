/* 給定ＲxＣ地圖和起點Ｓ，輸出從起點找到興奮源(２)的最短距離？
 * 解題核心：BFS
 * 特殊例子：起點就是興奮源
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxR=1e3;
const int MaxC=1e3;
const int INF=10;
int R, C;
int maze[MaxR][MaxC];
int step[MaxR][MaxC];
int dr[4]={ 0, 0,-1, 1};
int dc[4]={-1, 1, 0, 0};
struct NODE{
	int r, c;
	NODE(int r=0,int c=0):r(r),c(c){}
} S, now, nxt;
bool check(int r,int c){
	return r<0 or R<=r or c<0 or C<=c or step[r][c]<INF or (maze[r][c]&1);
}

int main(){
	
	cin>>R>>C>>S.r>>S.c;
	for(int r=0; r<R; r++)
		for(int c=0; c<C; c++){
			cin>>maze[r][c];
			step[r][c]=INF;
		}
	if( maze[S.r][S.c]==2 ){
		cout<<"0";
		return 0;
	}
	step[S.r][S.c]=0;
	queue<NODE> Q;
	Q.push(S);
	while( !Q.empty() ){
		now=Q.front(); Q.pop();
		for(int t=0; t<4; t++){
			nxt=NODE(now.r+dr[t],now.c+dc[t]);
			if( check(nxt.r,nxt.c) ) continue;
			step[nxt.r][nxt.c]=step[now.r][now.c]+1;
			if( maze[nxt.r][nxt.c]==2 ){
				cout<<step[nxt.r][nxt.c];
				return 0;
			}
			Q.push(nxt);
		}
	}
	cout<<"WAKUWAKU";
}