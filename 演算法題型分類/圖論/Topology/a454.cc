/* 題目沒有保證『單一起點和單一終點』=> 拓墣排序( 適用於 Directed Acyclic Graph )
 * 題解：http://mypaper.pchome.com.tw/zerojudge/post/1323147294
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int T, N, other;
  scanf("%d",&T);
  while(T--){
    // 讀取輸入
    scanf("%d",&N);
    vector<int> ford[N+1], back[N+1];
    vector<int> costDay(N+1,0);
    vector<int> acDay(N+1,0);
    vector<int> indegree(N+1,0);
    for(int st=1,ed;st<=N;st++)
      for(scanf("%d %d",&costDay[st],&other);other--;)
        scanf("%d",&ed),
        indegree[ed]++,
        ford[st].push_back(ed),
        back[ed].push_back(st);
    // 拓墣排序
    vector<bool> use(N+1,0);
    for(int unvis=N;unvis;){
      for(int i=1;i<=N;i++)
        if(indegree[i]==0 and use[i]==0){
          use[i]=true;
          unvis--;
          for(vector<int>::iterator it=back[i].begin(); it!=back[i].end(); it++)
            acDay[i]=max(acDay[i],acDay[*it]);
          acDay[i]+=costDay[i];
          for(vector<int>::iterator it=ford[i].begin(); it!=ford[i].end(); it++)
            indegree[*it]--;
        }
    }
    // 輸出需要最大的天數需求
    int ans=0;
    for(int i=1;i<=N;i++)
      ans=max(ans,acDay[i]);
    printf("%d\n",ans);
  }
}
/*
2
2
8 1 2
2 0
5
6 2 2 3
5 1 4
11 1 5
4 1 5
8 0

5
8 0
4 1 1
11 1 1
5 1 2
6 2 3 4
*/