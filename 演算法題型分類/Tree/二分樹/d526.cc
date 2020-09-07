/* 題目依照順序給定Ｎ個不重複的數字建二分樹，輸出前序(Pre-Order)：中前後
 * 解題關鍵：二分樹架構＋如何依照前序拜訪樹節點
 * 依據題目給訂的輸入順序建立二分樹
 */
#include<bits/stdc++.h>
using namespace std;

cont int MaxN=1005;
struct node{ int l, r, num; } T[MaxN];
void Prefix(int now){
  printf("%d ",T[now].num);
  if(T[now].l>0)  Prefix(T[now].l);
  if(T[now].r>0)  Prefix(T[now].r);
}
int main(){

  for(int N; scanf("%d",&N)!=EOF; ){
    /* new Root，左右節點的號碼預設是-1 */
    scanf("%d",&T[0].num);
    T[0].l=T[0].r=-1;

    for(int i=1;i<N;i++){
      scanf("%d",&T[i].num);
      T[i].l=T[i].r=-1;

      /* 從 Root 開始往下找到『適合』的位置，根據目前節點的數字大小判斷往左還是往右
       * 題目有保證不會出現重複的數字 
       */
      int now, nxt=0;
      while(nxt>=0)
        now=nxt, nxt=(T[i].num>T[nxt].num)?T[nxt].r:T[nxt].l;

      (T[i].num>T[now].num)? (T[now].r=i):(T[now].l=i);
    }
    Prefix(0), puts("");
  }
}