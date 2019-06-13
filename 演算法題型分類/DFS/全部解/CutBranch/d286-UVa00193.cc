// 題目要最大化塗黑點的數量，規定相鄰的點不可都塗黑，輸出最小字典序的答案
/* DFS暴力法＋剪枝＋Graph
 * 因為題目要求輸出最小字典序，所以依據點的編號由小到大枚舉(塗黑優先於留白)
 * 剪枝：目前塗黑的點數＋剩餘的點都塗黑(假設可以) 仍然比最佳解還少就停止遞迴
 */
#include<bits/stdc++.h>
using namespace std;

int N;
bool color[101];
vector<short> Link[101];
vector<short> ans, keep;
void DFS(int now,int i=0){
  if(keep.size()+N-now+1<ans.size()) // <- 關鍵：剪枝 TLE->3ms
    return;
  if(now>N){ // 沒有點可以往下，比對答案和目前的狀態取最佳解，因為展開時是以最小優先
    if(keep.size()>ans.size())
      ans=keep;
    return;
  }
  // 檢查該點能不能塗黑：檢查相鄰是不是有黑點，若沒有則嘗試將該點塗黑
  for(i=0;i<Link[now].size() and color[ Link[now][i] ]==0;i++);
  if(i==Link[now].size())
    color[now]=1,
    keep.push_back(now),
    DFS(now+1),
    keep.pop_back(),
    color[now]=0;
  // 跳過不塗黑，往下一個點前進
  DFS(now+1);
}
int main(){
  int T, K, a, b;
  scanf("%d",&T);
  while(T--){
    scanf("%d %d",&N,&K);
    for(int i=1;i<=N;i++)
      Link[i].clear();
    while(K--)
      scanf("%d %d",&a,&b),
      Link[a].push_back(b),
      Link[b].push_back(a);
    memset(color,0,sizeof(color));
    ans.clear();
    keep.clear();
    DFS(1);
    printf("%lu\n",ans.size());
    for(auto n:ans)
      printf("%d ",n);
    puts("");
  }
}
/*
3
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6

2 0

6 5
1 2
1 3
2 3
4 5
4 6
*/