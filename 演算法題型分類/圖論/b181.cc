// 簡單MST 但是題目沒有說明清楚n的意思以及答案要輸出的順序
#include<bits/stdc++.h>
using namespace std;

struct ee{
  int a=0, b=0, v;
  string ssa, ssb;
}tmp;
bool CompareBy_v(ee a,ee b){ return a.v<b.v; }
bool CompareBy_ss(ee a,ee b){ return (a.a==b.a)?(a.b<b.b):(a.a<b.a); }
int main(){
  for(int n,m; cin>>n>>m;){
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++)
      parent[i]=i;
    int Ncnt=0;
    vector<bool> vis(n+1,1);
    vector<ee> edge;
    for(int i=0;i<m;i++){
      cin>>tmp.ssa>>tmp.ssb>>tmp.v;
      tmp.a=(tmp.ssa.length()==2)?(tmp.ssa[1]-'0'):10;
      tmp.b=(tmp.ssb.length()==2)?(tmp.ssb[1]-'0'):10;
      // 題目沒有說明清楚 n 代表是編號最大的範圍，不是有n個點，得額外紀錄屬於某個號碼的點是不是存在
      if(vis[tmp.a]) Ncnt++, vis[tmp.a]=0;
      if(vis[tmp.b]) Ncnt++, vis[tmp.b]=0;
      edge.push_back(tmp);
    }
    sort(edge.begin(),edge.end(),CompareBy_v);
    vector<ee> ans;
    int cost=0;
    // Kruskal algoritm：停止條件:#edge=#node-1
    for(int i=0,cnt=1;i<m and cnt<Ncnt;i++){
      int pa=edge[i].a, pb=edge[i].b;
      while(parent[pa]!=pa) pa=parent[pa];
      while(parent[pb]!=pb) pb=parent[pb];
      if(pa!=pb){
        cost+=edge[i].v, ans.push_back(edge[i]), cnt++;
        if(pa<pb) pa^=pb^=pa^=pb;
        parent[pb]=pa;
      }
    }
    // 答案輸出時要按照字典序，但注意 W10>W2
    sort(ans.begin(),ans.end(),CompareBy_ss);
    for(int i=0;i<ans.size();i++)
      cout<<'('<<ans[i].ssa<<' '<<ans[i].ssb<<')'<<' ';
    cout<<endl<<cost<<endl;
  }
}