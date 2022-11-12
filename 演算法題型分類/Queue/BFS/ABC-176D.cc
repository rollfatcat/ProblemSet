#include<bits/stdc++.h>
using namespace std;

const int MaxR=1e3;
const int MaxC=1e3;
const int INF=1<<30;
// global
int R, C;
string ss;
int stp[MaxR][MaxC];

struct NODE{
	int r, c;
	NODE(int r=0,int c=0):r(r),c(c){}
} S, E;
deque<NODE> Q;
void DFS(int r,int c,int v){
	stp[r][c]=v;// setting
	// DFS :把不需要需要法力瞬移的格子都用遞迴走到
	if(0<=r-1 and stp[r-1][c]>v){ DFS(r-1,c,v); }
	if( r+1<R and stp[r+1][c]>v){ DFS(r+1,c,v); }
	if(0<=c-1 and stp[r][c-1]>v){ DFS(r,c-1,v); }
	if( c+1<C and stp[r][c+1]>v){ DFS(r,c+1,v); }
	// Backtrcking
	for(int dr=-2; dr<=2; dr+=1)
		for(int dc=-2; dc<=2; dc+=1){
			NODE nxt=NODE(r+dr,c+dc);
			if(0<=nxt.r and nxt.r<R and 0<=nxt.c and nxt.c<C and stp[nxt.r][nxt.c]==INF){
				stp[nxt.r][nxt.c]=v+1;
				Q.push_back(nxt);
			}
		}
}

int main(){
	// input
	cin>>R>>C;
	cin>>S.r>>S.c; S.r-=1; S.c-=1;
	cin>>E.r>>E.c; E.r-=1; E.c-=1;
	for(int r=0; r<R; r+=1){
		cin>>ss;
		for(int c=0; c<C; c+=1)
			stp[r][c]=(ss[c]=='#')? -1: INF;
	}
	// BFS
	stp[S.r][S.c]=0;
	Q.push_back(S);
	while(Q.empty()==0){
		NODE now=Q.front(); Q.pop_front();
		DFS(now.r,now.c,stp[now.r][now.c]);
	}
	if(stp[E.r][E.c]==INF)
		stp[E.r][E.c]=-1;
	cout<<stp[E.r][E.c]<<'\n';
}