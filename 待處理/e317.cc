#include<bits/stdc++.h>
using namespace std;

const int MAXN=101;
int clr[MAXN][MAXN]={};
bool vis[MAXN][MAXN]={};
struct NODE{
    int x, y, v;
    bool cd;
    NODE(int x=0,int y=0,int v=0,bool cd=0):x(x), y(y), v(v),cd(cd){};
    bool operator<(const NODE &rhs)const{ return v>rhs.v; }
};
int main(){
    int N, M, x, y, color;
    scanf("%d %d",&N,&M);
    while(M--)
        scanf("%d %d %d",&x,&y,&color),
        clr[x][y]=1<<color;
    
    priority_queue<NODE,vector<NODE> > PQ;
    PQ.push(NODE(1,1,0));
    bool getEnd=false;
    while(PQ.empty()==0){
        NODE now=PQ.top();
        if(now.x==N and now.y==N){ printf("%d\n",now.v), getEnd=true; break; }
        // 向四周延伸
        if()
    }
    if(getEnd==0) puts("-1");
}