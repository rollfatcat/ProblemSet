// 讀取優化(cin/cout是1.7s，自己寫getchar()是1.3s)＋set練習
/* 題解：https://home.gamer.com.tw/creationDetail.php?sn=4246722(原題目已刪除)
 * set.insert(x):將數字x插入集合中
 * set.size()：回傳目前集合中的數字個數
 * set.erase()：消除[L,R)，不包含右區間的數值
 * lower_bound(x)：回傳集合中大於等於x的數字(x存在的話就回傳位置沒有則回傳大於x的數值位置)
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){
  char c=getchar();
  bool sign=(c=='-');
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
}
int main(){

  int N, act, x, y;
  set<int> Nset;
  set<int>::iterator it;
  for(scanInt(N); N--; ){
    scanInt(act);
    if(act==1)
      scanInt(x), Nset.insert(x);
    else{
      scanInt(x),
      scanInt(y);
      it=Nset.lower_bound(y);
      if(it!=Nset.end() and (*it)==y) it++;
      Nset.erase(Nset.lower_bound(x),it);
    }
    if(Nset.size()<=1){
      if(Nset.size()==0) puts("0");
      else printf("1 %d\n",*Nset.begin());
    }else
      printf("2 %d %d\n",*Nset.begin(),*(--Nset.end()));
  }
}