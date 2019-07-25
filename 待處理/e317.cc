#include<bits/stdc++.h>
using namespace std;

const int MAXN=101;

int clr[MAXN][MAXN]={};
bool vis[MAXN][MAXN]={};
struct NODE{
    int x, y, v, c;
    bool cd;
    NODE(int x=0,int y=0,int v=0,int c=0,bool cd=0):x(x), y(y), v(v), c(c), cd(cd){};
    bool operator<(const NODE &rhs)const{ return v>rhs.v; }
} now;
int main(){
    int N, M, x, y, color, nxt_v, nxt_c;
    scanf("%d %d",&N,&M);
    while(M--)
        scanf("%d %d %d",&x,&y,&color),
        clr[x][y]=1<<color;
    priority_queue<NODE,vector<NODE> > PQ;
    PQ.push(NODE(1,1,0,clr[1][1],0));
    while(PQ.empty()==0){
        now=PQ.top(), PQ.pop();
        if(vis[now.x][now.y]) continue;
        vis[now.x][now.y]=true;
        if(now.x==N and now.y==N){ printf("%d\n",now.v); break; }
        // 向四周延伸
        if(now.x>1 and vis[now.x-1][now.y]==0 and (now.cd==0 or clr[now.x-1][now.y]) )
            nxt_c=(clr[now.x-1][now.y]==0)? now.c: clr[now.x-1][now.y],
            nxt_v=(now.c==clr[now.x-1][now.y])? now.v: now.v+(1<<(clr[now.x-1][now.y]==0)),
            PQ.push(NODE(now.x-1,now.y,nxt_v,nxt_c,clr[now.x-1][now.y]==0));
        if(now.y>1 and vis[now.x][now.y-1]==0 and (now.cd==0 or clr[now.x][now.y-1]) )
            nxt_c=(clr[now.x][now.y-1]==0)? now.c: clr[now.x][now.y-1],
            nxt_v=(now.c==clr[now.x][now.y-1])? now.v: now.v+(1<<(clr[now.x][now.y-1]==0)),
            PQ.push(NODE(now.x,now.y-1,nxt_v,nxt_c,clr[now.x][now.y-1]==0));
        
        if(now.x<N and vis[now.x+1][now.y]==0 and (now.cd==0 or clr[now.x+1][now.y]) )
            nxt_c=(clr[now.x+1][now.y]==0)? now.c: clr[now.x+1][now.y],
            nxt_v=(now.c==clr[now.x+1][now.y])? now.v: now.v+(1<<(clr[now.x+1][now.y]==0)),
            PQ.push(NODE(now.x+1,now.y,nxt_v,nxt_c,clr[now.x+1][now.y]==0));
        if(now.y<N and vis[now.x][now.y+1]==0 and (now.cd==0 or clr[now.x][now.y+1]) )
            nxt_c=(clr[now.x][now.y+1]==0)? now.c: clr[now.x][now.y+1],
            nxt_v=(now.c==clr[now.x][now.y+1])? now.v: now.v+(1<<(clr[now.x][now.y+1]==0)),
            PQ.push(NODE(now.x,now.y+1,nxt_v,nxt_c,clr[now.x][now.y+1]==0));
    }
    if(vis[N][N]==0) 
        puts("-1");
}
/*
1 1 0 0 0 
0 2 0 0 0 
0 0 2 1 0 
0 0 0 2 0 
0 0 0 0 1
過程模擬：
0 0 2 x x
2 1 3 6 x
x 3 3 4 6
x x 5 5 7
x x x 7 8
 */