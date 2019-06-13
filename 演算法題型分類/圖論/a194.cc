// (1) 題目要求最少路徑可以覆蓋整個 DAG 地圖：0.9s
/* 將數對之間大小的關係轉成 DAG，若Ｎi＜Ｎj，則有向邊由 nodeI 指向 node J
 * 暴力法線性把每個點當作起點往下一條走到底，若該點被拜訪過則跳過
 * 若該點是路徑上的終點時數量不會納入計算，輸出時記得要全部點數扣除數量。
 * (2) 題目的要求轉為：反向求一個非嚴格遞增的 LIS, 或者是正向的一個非嚴格遞減的 LDS
 * ZJ-a172 只能用(2)的解法通過
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=501;
vector<short> link[MAXN];
vector<short> ford;
vector<short> back;
vector<bool> use;

bool DFS(int now){
  for(vector<short>::iterator it=link[now].begin();it!=link[now].end();it++)
    if(use[*it]==0){
      use[*it]=1;
      if(back[*it]==0 or DFS(back[*it])){
        ford[now]=*it,
        back[*it]=now;
        return true;
      }
    }
  return false;
}
int main(){
  for(int N;scanf("%d",&N)!=EOF;){
    int num[501];
    for(int i=1;i<=N;i++)
      scanf("%d",&num[i]);
    // 建關係圖
    for(int i=1;i<=N;i++)
      link[i].clear();
    for(int i=1;i<=N;i++)
      for(int j=i+1;j<=N;j++)
        if(num[i]<num[j])
          link[i].push_back(j);
    //
    ford.clear(), ford.assign(N+1,0);
    back.clear(), back.assign(N+1,0);
    int cnt=0;
    for(int i=1;i<=N;i++)
      if(ford[i]==0){
        use.clear(), use.assign(N+1,0);
        if(DFS(i))
          cnt++;
      }
    printf("%d\n",N-cnt);
  }
}
/*
5
5 4 3 2 1
7
1 3 5 8 2 6 7
*/