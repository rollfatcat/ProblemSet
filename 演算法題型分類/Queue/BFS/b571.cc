/* 給定Ｒ×Ｃ的地圖內容，３種陷阱(Ａ/Ｂ/Ｃ)會因為每走動一格而切換，輸出由Ｘ走到Ｙ的最短距離？
 * 解題關鍵：最短距離＝BFS展開，狀態＝位置×哪種陷阱啟動
 * 實作細節：狀態紀錄需要考慮到不同陷阱啟動時能否抵達，所以除了位置還要考慮是哪種類型的陷阱啟動
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxR=5e2;
const int MaxC=5e2;
const int INF=1<<30;
char trap[MaxR][MaxC];
int step[MaxR][MaxC][3];
 
int main(){
	char ch;
	int R, C;
	deque< vector<int> >Q;
 
	scanf("%d %d\n",&R,&C);
	for(int r=0;r<R;r+=1,getchar())
		for(int c=0;c<C;c+=1){
			scanf("%c",&ch);
			trap[r][c]=ch;
			step[r][c][0]=(ch=='A' or ch=='#')? -1: INF;
			step[r][c][1]=(ch=='B' or ch=='#')? -1: INF;
			step[r][c][2]=(ch=='C' or ch=='#')? -1: INF;
 
			if(ch=='X'){
				Q.push_back( {r,c,1} );
				step[r][c][0]=0;
			}
		}
	int ans=-1;
	while(Q.empty()==0){
		vector<int> now=Q.front(); Q.pop_front();
		int type=now[2]%3;
		if(0<now[0] and step[now[0]-1][now[1]][ type ]==INF){
			step[now[0]-1][now[1]][ type ]=now[2];
			Q.push_back( {now[0]-1,now[1],now[2]+1} );
			if(trap[now[0]-1][now[1]]=='Y'){
				ans=now[2]; break;
			}
		}
		if(now[0]+1<R and step[now[0]+1][now[1]][ type ]==INF){
			step[now[0]+1][now[1]][ type ]=now[2];
			Q.push_back( {now[0]+1,now[1],now[2]+1} );
			if(trap[now[0]+1][now[1]]=='Y'){
				ans=now[2]; break;
			}
		}
		if(0<now[1] and step[now[0]][now[1]-1][ type ]==INF){
			step[now[0]][now[1]-1][ type ]=now[2];
			Q.push_back( {now[0],now[1]-1,now[2]+1} );
			if(trap[now[0]][now[1]-1]=='Y'){
				ans=now[2]; break;
			}
		}
		if(now[1]+1<C and step[now[0]][now[1]+1][ type ]==INF){
			step[now[0]][now[1]+1][ type ]=now[2];
			Q.push_back( {now[0],now[1]+1,now[2]+1} );
			if(trap[now[0]][now[1]+1]=='Y'){
				ans=now[2]; break;
			}
		}
	}
	printf("%d\n",ans);
}