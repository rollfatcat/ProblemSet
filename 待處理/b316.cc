// 樹形動態規劃：原理不清楚....
#include<bits/stdc++.h>
using namespace std;

const int MAXV=1001;
vector<int> E[MAXV];
int main(){

  int Vnum, Enum, Day;
  while(scanf("%d %d",&Vnum,&Enum)==2){
    scanf("%d",&Day);
    // init
    for(int i=0;i<Vnum;i++) E[i].clear();
    for(int u,v;Enum--;){
      scanf("%d %d",&u,&v);
      if(u>v) swap(u,v); // 有向邊(只會從節點編號小的走到大的)
      E[u].emplace_back(v);
    }
    for(int i=0;i<Vnum;i++) // 排序後確認選擇順序
      sort(E[i].begin(),E[i].end());
    // ?
    vector<int> pass(Vnum,0);
    pass[0]=--Day;
    for(int i=0;i<Vnum;i++){
      if(E[i].size()==0)	continue;
      int rem=pass[i]%E[i].size();
      for(int j=0;j<E[i].size();j++){
        int v=E[i][j];
        pass[v]+=rem;
        if(j<rem)
          pass[v]++;
      }

      for(int j=0;j<Vnum;j++)
        printf("%d ",pass[j]);
      puts("");
    }
    //
    int now=0;
    for(int x;E[now].size();now=E[now][x]) {
      x=pass[now]%E[now].size();
  		//printf("%d -> ", now);
    }
    printf("%d\n", now);
  }
}
/*
5 6 4
0 1
0 2
2 1
3 2
4 0
4 1
5 5 3
0 1
0 4
3 1
4 0
4 2
*/