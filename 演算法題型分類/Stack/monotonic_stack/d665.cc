/* 給定Ｎ個數字，合併Ｎ-1次，求最小化的『合併』成本總和？
 * 兩個相鄰的數字才能合併，合併時兩數中較小值的會被消去且該次合併成本＝較大值。
 * 觀察：根據合併的消除規則，兩側的數字只會越來越大。
 *      若兩側數字皆大於等於目前的數字時，則該數字可以優先被消除(無關乎現在這個數字大小)。
 *      將上述規則套用到最左側的點，消除成本只能取右側，考慮右側點的情況：
 *          較大或等於時則『合併』此時現在的點被消除
 *          較小時則點被保留下來，並且以較小的點當作新標準。
 *      上述的程序可以透過"Stack"完成，由左而右跑一遍後留下來的點必定呈現嚴格遞減。
 *      Stack內的數字做合併時，合併成本必定為最頂端的下個數字。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
int main(){
  int N, v;
  scanf("%d\n",&N);

  long sum_cost=0;
  stack<int> S;
  while(N--){
  	scanf("%d\n",&v);
    while(S.empty()==0 and S.top()<=v){
  	  S.pop();
      sum_cost+=(S.empty()==0)? min(S.top(),v): v
    }
    S.push(v);
  }
  for(;S.size()>1;S.pop(),sum_cost+=S.top());
  printf("%ld\n",sum_cost);
}