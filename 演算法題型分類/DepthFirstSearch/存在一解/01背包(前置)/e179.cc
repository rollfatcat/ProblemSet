/* DFS 找到一組解即停止
 * 1 ≦ n ≦ 20，1 ≦ k ≦ n，0 ≦ target ≦ 2e7
 * 剪枝：(1)現在的總合已經超過目標 (2)挑選的範圍要考慮還未挑選的數量
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

int N, K, target;
int money[MAXN];
bool DFS(int now,int st,int sum){
  if(now==K) return sum==target;
  if(st==N or sum>target) return false;
  for(int i=st;i<=N-K+now;i++)
    if(DFS(now+1,i+1,sum+money[i]))
      return true;
  return false;
}
int main(){
  while(scanf("%d%d%d",&N,&K,&target)!=EOF){
    for(int i=0;i<N;i++)
      scanf("%d",&money[i]);
    puts( DFS(0,0,0)?"YES":"NO" );
  }
}
/*
5 2 3
1 2 3 4 5
5 3 3
1 2 3 4 5
5 4 10
1 2 3 4 5
5 1 0
1 2 3 4 5
*/