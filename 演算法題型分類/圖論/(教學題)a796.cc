/* (圖論)題目會給點線圖
 * (1) 某一個城市跟多少個城市有路可以直接連通(不經由其他城市)
 * (2) 某兩城市間是否有一條路直接連通(不經由其他城市)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=101;
vector<int> node[MAXN];
int main(){

  int node_cnt, route_cnt, u, v;
  scanf("%d %d",&node_cnt,&route_cnt);
  for(int i=0;i<route_cnt;i++)
    scanf("%d %d",&u,&v),
    node[u].push_back(v),
    node[v].push_back(u);
  for(int i=1;i<MAXN;i++)
    sort(node[i].begin(),node[i].end());
  int Q, act;
  scanf("%d",&Q);
  while(Q--){
    scanf("%d",&act);
    if(act==1)
      scanf("%d",&u),
      printf("%lu\n",node[u].size());
    else
      scanf("%d %d",&u,&v),
      puts((*lower_bound(node[u].begin(),node[u].end(),v)==v)?"Yes":"No");
  }
}