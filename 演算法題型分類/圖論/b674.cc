/* 這是圖論的題目,確認一個組有向邊是否成為樹,只須確認幾點
 * 1.邊的數量是否為點的數量減一
 * 2.不存在循環路徑(cycle)
 * 3.所有的點一值追尋其父點都會找到同一點,也就是root
 */
#include<iostream>
#include<vector>
#include<set>
#include<cstring>
using namespace std;

vector<int> e[1001];
int P[1001];
bool IsTree, vis[1001];//偵測環
int DFS(int now){
  if(e[now].size()>1) IsTree=0;
  if(!e[now].size() or vis[now])  return P[now];
  vis[now]=1;
  return P[now]=DFS(e[now][0]);
}
int main(){
  for(int N; cin>>N and N;){
    for(int i=1;i<=1000;i++)
      e[i].clear(), vis[i]=P[i]=0;
    int cnt=0;
    for(int i=0,u,v; i<N; i++){
      cin>>u>>v;
      e[v].push_back(u);
      if(!P[u]) cnt++,P[u]=u;
      if(!P[v]) cnt++,P[v]=v;
    }
    if(cnt!=N+1){ cout<<"n"<<endl; continue; }
    IsTree=1;
    int keep=0;
    for(int i=1;i<=1000;i++)
      if(P[i] and !vis[i]){
        int a=DFS(i);
        if(!keep) keep=a;
        if(a!=keep){ IsTree=0; break; }//代表有兩個Root
      }
    cout<<((IsTree)?'y':'n')<<endl;
  }
}