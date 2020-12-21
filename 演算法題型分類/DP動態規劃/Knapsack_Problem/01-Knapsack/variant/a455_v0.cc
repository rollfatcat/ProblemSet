// 題解:http://mypaper.pchome.com.tw/zerojudge/post/1323227323
// 0/1背包+Greedy -> 35ms，想法如下但無法證實一定會對...IDDFS可以保證正確
/* 目標是最大化放入箱子的物品數量
 * 盒子容量小的能塞滿就塞，再滿足容量大的
 * 物品則是從大的開始放，能先放入箱子裡就先放
 */
#include<bits/stdc++.h>
using namespace std;

int box_num, item_num;
int box[50], w[1000];
int main(){
  scanf("%d %d",&box_num,&item_num);
  int max_box=0;
  for(int i=0;i<box_num;i++)
    scanf("%d",&box[i]);
  for(int i=0;i<item_num;i++)
    scanf("%d",&w[i]);
  sort(box,box+box_num);
  sort(w,w+item_num);
  vector<bool> use(item_num,0);
  int cnt=0;
  // 從容量小的盒子開始裝
  for(int i=0;i<box_num;i++){
    // 針對現在的背包做 0/1背包
    vector<int> DP[box[i]+1];
    vector<int> one_DP(box[i]+1,0);
    for(int j=item_num-1; j>=0; j--)
      if(!use[j])
        for(int k=box[i]; k>=w[j]; k--)
          if(one_DP[k-w[j]]+1>one_DP[k]){
            one_DP[k]=one_DP[k-w[j]]+1;
            DP[k]=DP[k-w[j]],
            DP[k].push_back(j);
          }
    // 在最大化物品數量的情況下同時挑選體積最大且不超過現在盒子體積的組合
    cnt+=one_DP[box[i]];
    // 回朔：利用二維陣列把把用到的物品標記成『使用過』的狀態
    for(int j=0;j<DP[box[i]].size();j++)
      use[ DP[box[i]][j] ]=1;
  }
  printf("%d\n",cnt);
}