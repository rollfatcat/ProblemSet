/* 輸入的字串可能包含空白，注意讀取格式(可能要提供給學生讀取)
 * 簡單版本的 DisjointSet
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=201;
int nxt[MAXN]={};
char ss[MAXN];
char ans[MAXN];
int main(){
  int N, K, L;
  while(scanf("%d",&N) and N){
    for(int i=0;i<N;i++)
      scanf("%d",&nxt[i]),
      nxt[i]--;
    // === 找出每組循環的週期 ===
    vector<bool> vis(N+1,0);
    vector<int> cycle(N+1,0);
    for(int i=0;i<N;i++)
      if(vis[i]==0){
        vector<int> one_cycle;
        for(int now=i;vis[now]==0;now=nxt[now])
          one_cycle.push_back(now), vis[now]=1;
        for(int x:one_cycle)
          cycle[x]=one_cycle.size();
      }
    // === 根據Ｋ加密：對週期取餘數後利用迴圈找到位移的點 ===
    while(scanf("%d",&K) and K){
      // 先讀取一個空白字元後，剩餘部分都是輸入的測資(包含空白字元)
      for(getchar(),L=0;(ss[L]=getchar())!='\n';L++);
      // === 加密 ===
      for(int idx=0;idx<L;idx++){
        int now=idx;
        for(int t=K%cycle[idx]; t>0; now=nxt[now],t--);
        ans[now]=ss[idx];
      }
      for(int idx=L;idx<N;idx++){
        int now=idx;
        for(int t=K%cycle[idx]; t>0; now=nxt[now],t--);
        ans[now]=' ';
      }
      ans[N]='\0';
      puts(ans);
    }
    puts("");
  }
}