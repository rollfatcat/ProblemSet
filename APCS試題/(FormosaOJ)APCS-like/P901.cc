/* 掃描線＋線段轉為出入點時的離散化問題：計算切點是多少時重疊的區段最多
 * 想法：分情況討論(以下舉例時 K=10)
 * (1)  0 ≦ 線段長度 <  K，不管有沒有被切到都不會出現『合法』的線段
 * (2)  K ≦ 線段長度 < 2K，若沒有被切到則有一個『合法』的線段，若切到特定區域會讓這個合法線段分裂成兩個『不合法』線段
 *  ( -6, 6) → (-4, 4] → [-3, 4] → 入點-3 + 出點 4 → 切到入點時#線段-1，切到入點時#線段+1
 *  (x1,x2)  → (x2-K,x1+K] → [x2-K+1,x1+K]
 * (3) 2K ≦ 線段長度    ，若沒有被切到則有一個『合法』的線段，若切到特定區域會讓這個合法線段分裂成兩個『合法』線段
 *  (-10,10) → [ 0, 0] → [ 0, 1) → 入點 0 + 出點 1 → 切到入點時#線段+1，切到出點時#線段-1
 *  (x1,x2)  → (x1+K,x2-K]  → [x1+K,x2-K+1)
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+1;

struct NODE{
  int pos; int add;
  bool operator<(const NODE &rhs)const{ return pos<rhs.pos; }
  NODE(int p=0,int a=0):pos(p),add(a){}
} ;
NODE cut_node[MAXN<<1]; // 紀錄 K ≦ 線段長度的出入點
int main(){
  int caseT, N, K, K2;
  int now_cnt; // 未切時的合法線段數量
  int cut_cnt; // 切點的數量
  int x1, x2, y;

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d",&N,&K);
    K2=K<<1;

    now_cnt=cut_cnt=0;
    for(int i=0;i<N;i++){
      scanf("%d %d %d %d",&x1,&y,&x2,&y);
      if(x1>x2) swap(x1,x2);
      if(x2-x1>=K2)
        cut_node[cut_cnt++]=NODE(x1+K,1),
        cut_node[cut_cnt++]=NODE(x2-K+1,-1),
        now_cnt++;
      else if(x2-x1>=K)
        cut_node[cut_cnt++]=NODE(x2-K+1,-1),
        cut_node[cut_cnt++]=NODE(x1+K,1),
        now_cnt++;
    }
    // 此時的 now_cnt 代表沒有切任何一刀時的#合法線段
    // 排序方式：點的一維位置由小到大
    sort(cut_node,cut_node+cut_cnt);

    // 掃一遍所有節點，把同個位置的變量合併在一起
    int max_cnt=cut_cnt; cut_cnt=0;
    for(int idx=1; idx<max_cnt; idx++)
      (cut_node[cut_cnt].pos==cut_node[idx].pos)?
        cut_node[cut_cnt].add+=cut_node[idx].add:
        cut_node[++cut_cnt]=cut_node[idx];
    ++cut_cnt; // 最後一個點的數量記得要+1

    // 掃描線：枚舉所有的切點位置
    max_cnt=now_cnt; // 預設值：當一刀都不切時的合法數量
    for(int cut_idx=0; cut_idx<cut_cnt; cut_idx++)
      now_cnt+=cut_node[cut_idx].add,
      max_cnt=max(max_cnt,now_cnt);
    // 輸出
    printf("%d\n",max_cnt);
  }
}
/*
4
4 5
 -5 10  5 10
-12  3  5  3
 -2 -4  5 -4
  5 -7  8 -7
4 5
 -5 10  5 10
-12  3  -2 3
 -2 -4  4 -4
  5 -7  8 -7
5 5
0 0 10 0
0 1 10 1
1 2  9 2
1 3  9 3
1 4 10 4
2 5
0 0 11 0
1 2  9 2
*/