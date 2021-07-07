/* 題目連結：https://atcoder.jp/contests/abc170/tasks/abc170_f
 * 給定的地圖(Ｈ×Ｗ ≤ 1e6)、一次可以朝著某方向"移動Ｋ格"，從起點"移動"到終點最少需要幾次？
 * 依照移動次數展開(BFS)，只要找到終點就可以跳開。
 * 從現在這個格子"朝著某個方向移動"時，若達成以下任一條件則跳開 
 *      超過邊界 或 碰到牆壁 或 距離起點(下個格子)≤距離起點(現在格子)
 * 只有當『距離起點(下個格子)＞距離起點(現在格子)+1』時才需要把位置放到 Queue 做展開。
 * 盲點：當『距離起點(下個格子)＝距離起點(現在格子)+1』時不能跳開要『繼續依照同個方向』更新！
 */
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MaxRC=1e3;
int dx[4]={ 0, 1, 0,-1};
int dy[4]={ 1, 0,-1, 0};

struct DATA{
	int x, y;
	DATA(int x=0,int y=0):x(x),y(y){}
} st, ed, now, nxt;

int main(){
	int R, C, K;
	while(scanf("%d %d %d\n",&R,&C,&K)!=EOF){
		
		vector<vector<char>> mat(R, vector<char>(C));
		for(int i=0;i<R;i++,getchar())
			for(int j=0;j<C;j++)
				mat[i][j]=getchar();
		scanf("%d %d %d %d\n",&st.x,&st.y,&ed.x,&ed.y);
		st.x--, st.y--, ed.x--, ed.y--;
		
		vector<vector<int>> step(R, vector<int>(C,INF));
		queue<DATA> Q;
		Q.push(DATA(st.x,st.y));
		step[st.x][st.y]=0;
		while(Q.empty()==0){
			now=Q.front(); Q.pop();
			if(now.x==ed.x and now.y==ed.y) break;
			for(int i=0;i<4;i++)
				for(int k=1;k<=K;k++){
					nxt=DATA(now.x+k*dx[i],now.y+k*dy[i]);
					if(nxt.x==-1 or nxt.x==R or nxt.y==-1 or nxt.y==C or mat[nxt.x][nxt.y]=='@' or step[nxt.x][nxt.y]<=step[now.x][now.y])
						break;
					if(step[nxt.x][nxt.y]>step[now.x][now.y]+1){
						step[nxt.x][nxt.y]=step[now.x][now.y]+1;
						Q.push(nxt);
					}
				}
		}
		printf("%d\n",(step[ed.x][ed.y]==INF)? -1: step[ed.x][ed.y]);
	}
}


