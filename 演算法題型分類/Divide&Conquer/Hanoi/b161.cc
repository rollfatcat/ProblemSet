/* 給定 ２Ｎ 個圓盤(編號１-Ｎ的圓盤各２個)，按照「河內塔規則」從最左邊的柱子全數搬移到最右邊的柱子時需要的最少步驟？
 * 解題關鍵：動態規劃(Bottom-Up)＋大數運算
 * 動態規劃-狀態轉移：ƒ(Ｎ)＝ƒ(Ｎ-1)+２＋ƒ(Ｎ-1)
 */
#include<bits/stdc++.h>
using namespace std;

const long base=1e18;
vector<long> DP[200];
int main(){
  DP[1].push_back(2);
  for(int now=2;now<=200;now++){
    long carry=2;
    for(auto n:DP[now-1])
      DP[now].push_back((n<<1)+carry),
      carry=DP[now].back()/base,  DP[now].back()%=base;
    if(carry) DP[now].push_back(carry);
  }
  for(int N; scanf("%d",&N)!=EOF;){
    printf("%ld",DP[N].back());
    for(int i=DP[N].size()-2;i>=0;i--)
      printf("%018ld",DP[N][i]);
    putchar('\n');
  }
}