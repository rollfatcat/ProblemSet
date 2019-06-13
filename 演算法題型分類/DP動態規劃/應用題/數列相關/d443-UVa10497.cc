// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4167536
/* DP規則解釋：DP[N]=(N-1)x(DP[N-1]+DP[N-2])
 * 考慮從狀態(N-1)推導到狀態N
 * (1)最後一個位置放N，和前面已經合法狀態的N-1個位置中挑一個做交換
 * (2)最後一個位置放N，和在狀態N-2時是合法但是有個位置是非法，透過該位置和N交換變成合法狀態
 * 推導規則後知道該做大數加法和乘法，MaxN=800, base改為1000000000做單位速算
 * 對照 b219的DP規則
 */
#include<iostream>
#include<vector>
using namespace std;
#define base 1000000000

vector<long> DP[801];
int main(){
  DP[0].push_back(0),
  DP[1].push_back(0),
  DP[2].push_back(1),
  DP[3].push_back(2);
  for(int now=4,carry,i;now<=800;now++){
    // 遞迴 : DP[N]=(N-1)x(DP[N-1]+DP[N-2])
    // 大數加法
    DP[now]=DP[now-1];
    for(carry=i=0;i<DP[now-2].size();i++)
      DP[now][i]+=DP[now-2][i]+carry, carry=DP[now][i]/base, DP[now][i]%=base;
    for(i=DP[now-2].size();i<DP[now-1].size();i++)
      DP[now][i]+=carry, carry=DP[now][i]/base, DP[now][i]%=base;
    if(carry) DP[now].push_back(carry);
    // 大數乘法
    for(carry=i=0;i<DP[now].size();i++)
      DP[now][i]=(now-1)*DP[now][i]+carry, carry=DP[now][i]/base, DP[now][i]%=base;
    if(carry) DP[now].push_back(carry);
  }
  // 輸出比較
  for(int n;scanf("%d",&n) and n>=0;){
    printf("%lu",DP[n].back());
    for(int i=DP[n].size()-2;i>=0;i--)
      printf("%09lu",DP[n][i]);
    printf("\n");
  }
}
/*
0
1
2
9
44
265
1854
14833
133496
1334961
*/