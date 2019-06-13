// 想法參考：http://alrightchiu.github.io/SecondRound/flow-networksmaximum-flow-ford-fulkerson-algorithm.html
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 101

int n, m, st, ed, a, b, c;
int capacity[MaxN][MaxN];
int getMaxFlow(){
  int sumFlow=0;
  while(true){
    int flow[n+1];
    int from[n+1];
    memset(flow,0,sizeof(flow));
    memset(from,0,sizeof(from));
    flow[st]=0x7fffffff; //Source有無限的流量
    queue<int>Q;
    Q.push(st);
    //BFS展開求最少的#edge到達Target
    while(!Q.empty() and flow[ed]==0){
      int now=Q.front();  Q.pop();
      for(int nxt=1;nxt<=n;nxt++)
        // 另一個點還沒走過而且到到達該點還有流量
        if(flow[nxt]==0 and capacity[now][nxt]>0)
          Q.push(nxt),  from[nxt]=now,  flow[nxt]=min( flow[now], capacity[now][nxt]);
    }
    // 沒有任何流量到達Target
    if(flow[ed]==0) break;
    // 把這一條path上的capacity都扣掉流到Target的流量
    for(int now=ed;now!=st;now=from[now])
      capacity[from[now]][now]-=flow[ed];
    sumFlow+=flow[ed];
  }
  return sumFlow;
}
int main(){
  for(int caseNum=1;scanf("%d",&n) and n;caseNum++){
    scanf("%d%d%d",&st,&ed,&m);
    memset(capacity,0,sizeof(capacity));
    while(m--)
      scanf("%d%d%d",&a,&b,&c), capacity[a][b]=capacity[b][a]=(capacity[a][b]+c);
    printf("Network %d\nThe bandwidth is %d.\n\n",caseNum,getMaxFlow());
  }
}
/* 說明網站的例子測資
6
5 6 10
1 2 3
1 3 8
2 6 9
2 4 2
3 2 7
3 4 7
4 2 4
4 6 8
5 1 9
5 3 9
*/
