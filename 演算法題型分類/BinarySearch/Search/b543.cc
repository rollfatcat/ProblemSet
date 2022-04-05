// 主要是DFS條件式展開搜索網絡，二分搜尋＋映射表只是加速的方式
/* v1(200ms)：暴力解(沒經過排序)
 * v2( 52ms)：根據防禦力排序，二分搜尋法找到所有防禦力低於現在員工的攻擊力
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, cnt, Nomap[5000]; // Nomap是建立號碼配對(Nomap[原始號碼]=排序後的號碼)
bool vis[5000];
struct nn{
  int no, lv, atk, dfs;
  bool operator<(const nn other)const{ return(dfs==other.dfs)?(lv<other.lv):(dfs<other.dfs); }
} person[5000];
inline void scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int BS(int t){
  if(t>person[N-1].dfs) return N;
  int l=0, r=N-1, m;
  while(l<=r){
    m=(l+r)>>1;
    if(person[m].dfs>=t)  r=m-1;
    else l=m+1;
  }
  return l;
}
void DFS(int now){ // now是經過排序的大小，不是原始的順序
  cnt++,
  vis[person[now].no]=true;
  int Rbound=BS(person[now].atk);
  for(int i=0;i<Rbound;i++)
    if(person[now].lv>person[i].lv and !vis[person[i].no])
      DFS(i);
}
int main(){
  int T, no;
  for(scanInt(T);T--;){
    scanInt(N);
    for(int i=0;i<N;i++)
      vis[i]=0,
      person[i].no=i,
      scanInt(person[i].lv),
      scanInt(person[i].atk),
      scanInt(person[i].dfs);
    // 先記錄起始點，避免排序後導致號碼抓錯
    scanInt(no),
    no--;
    sort(person,person+N);
    for(int i=0;i<N;i++) // 建立映射表
      Nomap[person[i].no]=i;
    cnt=0,
    DFS(Nomap[no]);
    printf("%d\n",cnt);
  }
}