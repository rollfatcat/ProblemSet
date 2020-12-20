// 一般來說01背包問題是重量限制，而這題特殊之處在於以『力矩』為限制
// 題解：https://allem40306.github.io/blog/2018/04/15/zjc264_神奇的載物任務
/* 力矩:為長度乘以重量 => 所以越重的物體放越前面(長度越短)越好，所以先排序一遍。
 * 一般的01背包問題可以用一維的陣列實作，枚舉所有的重量狀態下最大價值，
 * 對應到這題需要枚舉的維度要改為『力矩』=> 拆成『重量』x『長度』兩個維度更新
 * 所以動態規劃的兩個維度分別是長度和力矩，陣列紀錄的是當下最大的價值。
 * (問題) 既然是由01背包的一維實作改良過來的，為何物品需要從體積最大的開始放置呢？
 */
#include<bits/stdc++.h>
using namespace std;

struct ITEM{
  int w,v;
  bool operator<(const ITEM &rhs)const{ return w>rhs.w; }
}item[200];
int DP[201][1001]={}; // [長度][力矩]
int main(){
  int N, T, L;
  scanf("%d %d %d",&N,&T,&L);
  for(int i=0;i<N;i++)
    scanf("%d %d",&item[i].w,&item[i].v);
  /* 排序可以保證同種重量的組合底下力矩最小化
   * 換句話說排序只會優化答案，且必定比不排序好。
   * 觀察這組測資
   * 2 4 2
   * 1 1
   * 2 3
   * 最佳解是重量１的物品放在長度２＋重量２的物品放在長度１，
   * 重量２的物品先於重量１的物品更新時
   *   0 3 0 0     1 3 0 0
   *   0 0 0 3     0 1 0 4
   * 但下述的更新方式不會更新到這個組合，因為更新方向只會從長度由低到高(中間表格)
   * 重量１的物品先於重量２的物品更新時(右邊才是正確的)
   *   1 0 0 0     1 3 0 0     1 3 0 4
   *   0 1 0 0     0 1 0 3     0 1 0 3
   */
  sort(item,item+N);
  for(int i=0;i<N;i++){
    for(int j=min(T/item[i].w,L); j>1; j--){
      int torque=j*item[i].w;
      for(int k=T; k>=torque; k--)
        if(DP[j-1][k-torque])
          DP[j][k]=max(DP[j][k],DP[j-1][k-torque]+item[i].v);
    }
    DP[1][item[i].w]=max(DP[1][item[i].w],item[i].v);
  }
  int ans=0;
  for(int i=1;i<=L;i++)
    for(int j=1;j<=T;j++)
      ans=max(ans,DP[i][j]);
  printf("%d\n",ans);
}
/*
2 4 2
1 1
2 3

3 10 3
1 1
2 3
3 5
*/