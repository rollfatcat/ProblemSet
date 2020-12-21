// 題解：https://blog.csdn.net/yeyeyeguoguo/article/details/42325863
// 難在次數的計算：次數的計算只和『有放垃圾的格子』有關
/* 第一眼看到認為是點對點之間，如果有Dominate即是有一條path，對起終點找到一條最大流量和方法數
 * 和UVA的差異是題目不需要輸出字典序最低的路徑
 * 把有放垃圾的格子當作 Node，先針對 Node 對排序
 * 之後DP，判斷目前 node 的 y 座標小於之前 node 的 y 座標時試著更新(效率差在這邊)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=102;
int R, C, Ncnt;
struct nn{
  int x, y, num, cnt;
  bool operator<(const nn other)const{ return (x==other.x)?(y<other.y):(x<other.x); }
} node[MAXN*MAXN];
bool mp[MAXN][MAXN];
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int caseN=1;cin>>R>>C and R>-1;caseN++){
    memset(mp,0,sizeof(mp));
    Ncnt=0;
    for(int x,y; cin>>x>>y and x;)
      mp[x][y]=true,
      node[Ncnt++]={x,y,1,1};
    sort(node,node+Ncnt);
    if(!mp[R][C])
      node[Ncnt++]={R,C,1,1};
    // --- DP ---
    for(int i=0;i<Ncnt;i++){
      for(int j=0;j<i;j++)
        if(node[j].y<=node[i].y){
          if(node[i].num==node[j].num+1)
            node[i].cnt+=node[j].cnt;
          else if(node[i].num<node[j].num+1){
            node[i].num=node[j].num+1;
            node[i].cnt=node[j].cnt;
          }
        }
      //printf("%d %d : %d %d\n",node[i].x,node[i].y,node[i].num,node[i].cnt);
    }
    if(!mp[R][C])
      node[Ncnt-1].num--;
    // ---輸出---
    cout<<"CASE#"<<caseN<<": "<<node[Ncnt-1].num<<' '<<node[Ncnt-1].cnt<<'\n';
  }
}