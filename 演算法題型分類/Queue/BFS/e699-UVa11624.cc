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
 
const int MaxR=1e3;
const int MaxC=1e3;
const int INF=1<<30;
char ss[MaxC+2];
int  stp[MaxR][MaxC];
int dx[4]={ 1,-1, 0, 0};
int dy[4]={ 0, 0, 1,-1};
 
int main(){
	int caseT, R, C;
 
	scanf("%d",&caseT);
	while(caseT-->0){
		deque<vector<int>> Q;
		vector<int> S;
		scanf("%d %d",&R,&C);
		for(int r=0;r<R;r+=1){
			scanf("%s",ss);
			for(int c=0;c<C;c+=1){
				switch(ss[c]){
					case 'J':
						S={r,c,0};
					case '.':
						stp[r][c]=INF;
						break;
					case 'F':
						Q.push_back({r,c,1});
					case '#':
						stp[r][c]=-INF;
				}
			}
		}
		// "火焰"展開的順序先於"人"，所以"人"存入 Queue 時必須慢於"火焰" ... 先紀錄後存入 
		Q.push_back(S);
		stp[S[0]][S[1]]=0;
		bool escape=false;
		while(Q.empty()==0 and escape==0){
			vector<int> now=Q.front(); 
			Q.pop_front();
			for(int i=0;i<4;i+=1){
				vector<int> nxt=now;
				nxt[0]+=dx[i]; 
				nxt[1]+=dy[i];
				if(nxt[2]){ 
					if(nxt[0]==-1 or nxt[0]==R or nxt[1]==-1 or nxt[1]==C or stp[nxt[0]][nxt[1]]<=0 )
						continue;
					stp[nxt[0]][nxt[1]]=-stp[nxt[0]][nxt[1]];
				}else{
					if(nxt[0]==-1 or nxt[0]==R or nxt[1]==-1 or nxt[1]==C){
						escape=true;
						printf("%d\n",abs(stp[now[0]][now[1]])+1);
						break;
					}
					if(stp[nxt[0]][nxt[1]]<INF)
						continue;
					stp[nxt[0]][nxt[1]]=abs(stp[now[0]][now[1]])+1;
				}
				Q.push_back(nxt);
			}
		}
		if(escape==false)
			puts("IMPOSSIBLE");
	}
}