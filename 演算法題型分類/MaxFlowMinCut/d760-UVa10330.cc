// 扣除整條路徑上的最小流量時注意需要回填反向的流量, 不然第19/27/42會出現錯誤!!
// 但 UVA00820不扣除也不會出現Error
// 這一題和UVA00820差異是電線是單向傳輸, 且點本身多了『容量限制』
// 點含有容量限制,就把這個點拆分成兩個部分：In/Out 初始化時一條edge由In指向Out

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MaxN 202
#define INF 0x7fffffff

int N, M, endN;
int capacityEdge[MaxN][MaxN];
int getMaxFlow(){
  int sumFlow=0;
  while(true){
    int flow[endN+1];
    int from[endN+1];
    memset(flow,0,sizeof(flow));
    memset(from,0,sizeof(from));
    queue<int> Q;
    Q.push(0);
    flow[0]=INF;
    while(!Q.empty() and flow[endN]==0){
      int now=Q.front();  Q.pop();
      for(int nxt=0;nxt<=endN;nxt++)
        if(flow[nxt]==0 and capacityEdge[now][nxt]>0)
          Q.push(nxt),
          from[nxt]=now,
          flow[nxt]=min(flow[now],capacityEdge[now][nxt]);
    }
    if(flow[endN]==0) break;
    for(int now=endN;now!=0;now=from[now])
      capacityEdge[from[now]][now]-=flow[endN],
      capacityEdge[now][from[now]]+=flow[endN];
    sumFlow+=flow[endN];
  }
  return sumFlow;
}
int main(){
  int a, b, c, st_num, ed_num;

  while(cin>>N){
    // 0=Source, endN=Target
    endN=2*N+1;
    memset(capacityEdge,0,sizeof(capacityEdge));
    // In=2*i-1, Out=2*i
    for(int i=1;i<=N;i++)
      cin>>capacityEdge[2*i-1][2*i];
    cin>>M;
    while(M--) // a的out接到b的in
      cin>>a>>b>>c, capacityEdge[2*a][2*b-1]+=c;
    cin>>st_num>>ed_num;
    while(st_num--) cin>>a, capacityEdge[0][2*a-1]=INF;  // Source 接到a的in
    while(ed_num--) cin>>a, capacityEdge[2*a][endN]=INF; // a的out 接到 Target
    cout<<getMaxFlow()<<endl;
  }
}
/*
6
100 100 100 100 100 100
10
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
1 1
5 6
*/