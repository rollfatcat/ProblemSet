/* 一名玩家要逃離火場，玩家移動的過程中火也會一並蔓延，判斷玩家是否能逃出火場
 * 同個時刻當火焰蔓延和玩家抵達同個格子時該格子視為火焰優先
 * 用同一個 Queue 一次處理玩家和火焰的移動但做 BFS 時火焰的優先權優先(先推入Queue)
 * 而後將玩家推入 Queue，根據 Queue 的特性：同步移動時優先處理火焰的蔓延。
 * BFS 紀錄的單位除了二維座標，還需要步數和屬性(玩家/火焰)。
 * 題目『逃出』的定義是移動的邊界外＝玩家能移動到邊界後『再多走一步』即可，
 * 因為火焰無法蔓延到邊界外，所以只要玩家走到邊界火焰便無法阻止。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxSz=1000;
char mapss[MaxSz][MaxSz];
struct NODE{
	int x, y, d, s;
	NODE(int x=0,int y=0,int d=0,int s=0):x(x),y(y),d(d),s(s){}
} now, st;

int main(){
	int caseT, R, C; 
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%d %d\n",&R,&C);
		queue<NODE> Q;
		for(int i=0;i<R;i++){
			scanf("%s\n",mapss[i]);
			for(int j=0;mapss[i][j]!='\0';j++)
				     if(mapss[i][j]=='F') Q.push(NODE(i,j));
				else if(mapss[i][j]=='J') st=NODE(i,j,0,1);
		}
		bool found=0;
		for(Q.push(st);Q.empty()==0;Q.pop()){
			now=Q.front();
			if(mapss[now.x][now.y]=='#') continue;
			if(now.s and (now.x==0 or now.x==R-1 or now.y==0 or now.y==C-1)){ printf("%d\n",now.d+1); found=1; break; }
			mapss[now.x][now.y]='#';
			if(now.x>0   and mapss[now.x-1][now.y]=='.') Q.push(NODE(now.x-1,now.y,now.d+1,now.s));
			if(now.x+1<R and mapss[now.x+1][now.y]=='.') Q.push(NODE(now.x+1,now.y,now.d+1,now.s));
			if(now.y>0   and mapss[now.x][now.y-1]=='.') Q.push(NODE(now.x,now.y-1,now.d+1,now.s));
			if(now.y+1<C and mapss[now.x][now.y+1]=='.') Q.push(NODE(now.x,now.y+1,now.d+1,now.s));
		}
		if(found==0) puts("IMPOSSIBLE");
	}
}