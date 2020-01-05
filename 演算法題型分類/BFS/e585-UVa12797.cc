/* APCS 的合適題(暴力法＋BFS)
 * 題目給訂的地圖由『前10個』大小寫的字母構成, 求最短路徑。
 * 但路徑上不能同時存在某個字母的大小寫 !!
 * 最短路徑＝BFS, 但即便抵達同一格的最短路徑時所需構成的字母不同
 * 『前10個字母』,暴力法枚舉10個字母的大小寫組合對應2^10種地圖做BFS後找到的最短路徑。
 * 最短路徑必須包含起點和終點, 這兩格對應的字母是『必選』其他有出現過的字母才做大小寫組合。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
const int INF=1<<30;
char mapch[MaxN][MaxN+2];
bool vis  [MaxN][MaxN+2];
bool pick[256]={};
int N, ShortPath;
struct DATA{
	int x, y, s;
	DATA(int x=0,int y=0,int s=0):x(x),y(y),s(s){}
} now;

inline int CharToS(char &ch){
	return (ch>='a')?ch-'a':ch-'A'; 
}
inline void CharDFS(int CharStatus){
	if(CharStatus==0){
		for(int i=0;i<N;i++)
			for(int pos,j=0;j<N;j++)
				vis[i][j]=pick[mapch[i][j]];
		queue<DATA> Q;
		Q.push(DATA(0,0,1));
		while(Q.empty()==0){
			now=Q.front(); Q.pop();
			if(vis[now.x][now.y]==0)
				continue;
			vis[now.x][now.y]=0;
			if(now.x==N-1 and now.y==N-1){
				ShortPath=min(ShortPath,now.s); return ;
			}
			if(now.x>0 and vis[now.x-1][now.y])
				Q.push(DATA(now.x-1,now.y,now.s+1));
			if(now.y>0 and vis[now.x][now.y-1])
				Q.push(DATA(now.x,now.y-1,now.s+1));
			if(now.x+1<N and vis[now.x+1][now.y])
				Q.push(DATA(now.x+1,now.y,now.s+1));
			if(now.y+1<N and vis[now.x][now.y+1])
				Q.push(DATA(now.x,now.y+1,now.s+1));
		}
		return;
	}
	int lastS=CharStatus&-CharStatus; CharStatus^=lastS;
	int pos=__lg(lastS);
	pick[pos+'A']=1, pick[pos+'a']=0, CharDFS(CharStatus);
	pick[pos+'A']=0, pick[pos+'a']=1, CharDFS(CharStatus);
}
int main(){
	while(scanf("%d\n",&N)!=EOF){
		int CharStatus=0;
		for(int i=0;i<N;i++){
			scanf("%s",mapch[i]);
			for(int j=0;mapch[i][j]!='\0';j++)
				CharStatus|=1<<CharToS(mapch[i][j]);
		}
		memset(pick,0,sizeof(pick));
		CharStatus^=1<<CharToS(mapch[0][0]),
		pick[mapch[0][0]]=1;
		if(mapch[0][0]!=mapch[N-1][N-1])
			CharStatus^=1<<CharToS(mapch[N-1][N-1]),
			pick[mapch[N-1][N-1]]=1;
		ShortPath=INF;
		CharDFS(CharStatus);
		printf("%d\n",(ShortPath==INF)?-1:ShortPath);
	}
}