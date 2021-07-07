// 對比：找『最近』的兩點距離 => CDQ
// O(N^2)：暴力法，枚舉每個點，找到最遠的點(本來會TLE) => 0.8s
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10000

struct NODE{
  int x, y, o;
  bool operator<(const NODE &rhs)const{ return (x<rhs.x) or (x==rhs.x and y<rhs.y); }
}node[MAXN];
int N, nowD;
int maxD[MAXN]={};

inline int NodeDis(NODE &a,NODE &b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
int main(){
  while(scanf("%d",&N)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d",&node[i].x),
      scanf("%d",&node[i].y),
      maxD[i]=0;
    for(int i=0;i<N;i++)
      for(int j=i+1;j<N;j++)
        nowD=NodeDis(node[i],node[j]),
        maxD[i]=max(maxD[i],nowD),
        maxD[j]=max(maxD[j],nowD);
    for(int i=0;i<N;i++)
      printf("%d\n",maxD[i]);
  }

}
/*
12
2 1
3 1
1 2
2 2
3 2
4 2
1 3
2 3
3 3
4 3
2 4
3 4

10
18 18
 1 15
10 14
18 13
19 12
 7 10
 8  9
20  9
10  6
 4  5
*/