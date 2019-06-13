// c010-uva10107的加強版:輸入的數量由1e4🔝2e5個
// 題解：http://cs.cysh.cy.edu.tw/php_system/acm_statistics/code.php?id=6723
/* multiset<int> + iterator，根據總數是奇偶數情況討論(100ms/9.5MB)，指標練習
 * 若偶數：新增的數比(*it)小則將(*it)及(it的前一個)相加÷2輸出
 *         新增的數比(*it)大或等於則將(*it)及(it的後一個)相加÷2輸出，且it後移一格
 * 若奇數：新增的數比(*it)大或等於(*it)則將(*it)輸出
 *         新增的數比(*it)小則將it前移一個，輸出新的(*it)
 * 以上it維持指向｛奇：中間、偶：中偏右｝
 * prev(iter,2):returns a copy of iter decremented by 2
 * next(iter,1):returns a copy of iter incremented by 1
 */
#include<bits/stdc++.h>
using namespace std;

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main() {
  multiset<int> Nset;
  int n;
  // 先讀取一個數字進來才能做比較
  scanInt(n), Nset.insert(n), printf("%d\n",n);
  multiset<int>::iterator it=Nset.begin();
  bool NumIsOdd=true;
  while(scanInt(n)){
    NumIsOdd^=true;
    Nset.insert(n);
    if(NumIsOdd){
      if(*it>n)
        it--;
      printf("%d\n",*it);
    }else{
      if(*it<=n)
        it++;
      printf("%d\n",((*it)+(*prev(it,1)))/2);
    }
  }
}