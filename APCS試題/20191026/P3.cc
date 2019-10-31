/* 題目要求最小化『次數』,不管往左還是往右都是+1次
 * 可以利用 BFS 和 Queue 搭配完成。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
int N, P, L, R;
int to[MaxN];
bool vis[MaxN];

struct DATA{
    int pos,cnt;
    DATA(int p=0,int c=0):pos(p),cnt(c){}
} now;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    /* 題目保證傳送過去的地點落在1e8, 代表可能超過邊界
     * 讀取測資時若傳送過去的地點超過邊界則將這格標記為『拜訪過』
     */
    cin>>N>>P>>L>>R;
    for(int i=0;i<N;i++)
        cin>>to[i], vis[i]=(to[i]>=N);
        
    int Lpos, Rpos, flash;
    queue<DATA> Q;
    Q.push(DATA());
    while(Q.empty()==0){
        now=Q.front(); Q.pop();
        vis[now.pos]=1;
        flash=to[now.pos];
        if(flash==P){
            vis[P]=1; cout<<now.cnt<<'\n'; break;
        }
        Lpos=flash-L;
        Rpos=flash+R;
        if(Lpos>=0 and vis[Lpos]==0)
            Q.push( DATA(Lpos,now.cnt+1) );
        if(Rpos<N  and vis[Rpos]==0)
            Q.push( DATA(Rpos,now.cnt+1) );
    }        
    if(vis[P]==0) 
        cout<<-1<<'\n';
}