/* 題目目標是最大化物品數量
 * -> 同樣數量時選擇體積總和小的
 * -> n個物品無法放入多個背包時，n+1 個物品必定也無法放入背包
 * -> 根據體積排序嘗試把 n 個物品放入多個背包內，成功時挑戰 n+1 個，失敗時輸出 n-1 個
 * -> IDDFS( Iterative Deepening DFS )
 * 剪枝：
 * (1)目前物品總和超過所有背包容量總合時必定裝不下去
 * (2)紀錄可以裝入前一個物品體積的背包號碼，當現在物品體積等同前一個物品體積時就從那個號碼開始放
 */
#include<bits/stdc++.h>
using namespace std;

int box_num, item_num;
int w[1000];
vector<int> box, tmp_box;
bool IDDFS(int item_idx,int pre_box){
  // 全部物品可以放入箱子內,回傳成功
  if(item_idx==-1)  return true;
  // 如果現在物品的重量等同之前那一項的重量時搜尋的範圍就從上一次可以裝入的箱子開始找 -> 剪枝
  int start=(item_idx>=0 and w[item_idx]==w[item_idx+1])?pre_box:0;
  for(int i=start;i<box_num;i++)
    if(tmp_box[i]>=w[item_idx]){
      tmp_box[i]-=w[item_idx];
      // 嘗試成功就回到上一層，沒有就回覆數值作為下一次的嘗試
      if(IDDFS(item_idx-1,i)) return true;
      tmp_box[i]+=w[item_idx];
    }
  // 嘗試所有的物品擺放入箱子的方式仍然無法全部擺入時回傳失敗
  return false;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  cin>>box_num>>item_num;
  int sum_box=0, x;
  for(int i=0;i<box_num;i++)
    cin>>x, sum_box+=x, box.push_back(x);
  for(int i=0;i<item_num;i++)
    cin>>w[i];
  sort(w,w+item_num);
  int sum_w=0, depth;
  for(depth=0;depth<item_num;depth++){
    // -> 剪枝：物品放入箱子的上限是目前物品總重量加總不會超過全部箱子的容量
    sum_w+=w[depth];
    if(sum_w>sum_box) break;
    // -> 剪枝：嘗試把目前物品放入箱子內，一但無法找到一種放法可以把全部放入時就跳開
    // 之後的物品重量都會大於目前的物品，更不可能放入
    tmp_box=box;
    if(!IDDFS(depth,-1)) break;
  }
  printf("%d\n",depth);
}
/*
3 9
2 21 5
3 3 3 5 5 7 8 8 9
*/