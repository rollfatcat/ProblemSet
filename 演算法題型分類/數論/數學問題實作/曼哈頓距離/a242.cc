/* 求下列的最小值 |a1x - x1|+|a2x - x2|+... +|anx - xn|……
 * 題目保證：a1|x1, a2|x2 ...... an|xn，|a1 + a2 + ... + an| ≤ 200000 或 1 ≤ n ≤ 100000
 * 從題目可以知道要求『曼哈頓』距離的最小化。
 * 但題目保證 an|xn 可以得知|anx - xn|＝an|x - xn/an|，等價於從 an個(xn/an) 中找到中位數即可
 */
#include<bits/stdc++.h>
using namespace std;

inline void scanInt(int &x){char c;for(x=0;(c=getchar_unlocked())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');}
int main(){
  int caseT, N;
  scanInt(caseT);
  while(caseT--){
    int a, x, tmp;
    vector<int> num;
    scanInt(N);
    while(N--){
      scanInt(a),
      scanInt(x);
      for(int i=0;i<a;i++)
        num.push_back(x/a);
    }
    sort(num.begin(),num.end());
    int mid=num[num.size()>>1];
    int sum=0;
    for(int x:num)
      sum+=abs(mid-x);
    printf("%d\n",sum);
  }
}