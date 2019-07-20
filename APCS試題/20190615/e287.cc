// 簡單DFS
#include<bits/stdc++.h>
using namespace std;

// 1 ≤ n, m ≤ 100
const int MAXN=100;
const int INF=1<<30;
int R, C, sumv;
int mapv[MAXN][MAXN]; // 每個數字都非負且小於 1e6 且都不相等
bool vis[MAXN][MAXN]={};
void DFS(int x,int y){
    // 加上這格的分數並紀錄這格已經走過
    sumv+=mapv[x][y], vis[x][y]=1;
    // 選擇四周的格子中『沒走過』的『分數值最小』那格作為下一次移動的目標
    int nxtv=INF, nxtx=-1, nxty=-1;
    if(x>0 and vis[x-1][y]==0 and nxtv>mapv[x-1][y]) nxtv=mapv[x-1][y], nxtx=x-1, nxty=y;
    if(y>0 and vis[x][y-1]==0 and nxtv>mapv[x][y-1]) nxtv=mapv[x][y-1], nxtx=x, nxty=y-1;
    if(x+1<R and vis[x+1][y]==0 and nxtv>mapv[x+1][y]) nxtv=mapv[x+1][y], nxtx=x+1, nxty=y;
    if(y+1<C and vis[x][y+1]==0 and nxtv>mapv[x][y+1]) nxtv=mapv[x][y+1], nxtx=x, nxty=y+1;
    // 若這格存在(可能會走到四周格子都是走過的狀態)則移動過去
    if(nxtv<INF)
        DFS(nxtx,nxty);
}
int main(){
    scanf("%d %d",&R,&C);
    int minv=INF, stx=-1, sty=-1;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++){
            scanf("%d",&mapv[i][j]);
            if(mapv[i][j]<minv)
                minv=mapv[i][j],
                stx=i, sty=j;
        }
    sumv=0;
    DFS(stx,sty);
    printf("%d\n",sumv);
}