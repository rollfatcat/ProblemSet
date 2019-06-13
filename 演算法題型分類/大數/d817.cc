// 根據巴斯卡三角形的特性：第n列的總和就是2^n, 0≤n≤5000, 就是大數加法
// 用 unsigned long long int 去存, 進位單位是1e18
// 核對用的表格(wiki提供)https://en.wikipedia.org/wiki/Power_of_two
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  unsigned long long int base=1000000000000000000; // 1e18
  vector<unsigned long long int> power2[5001];
  power2[0].push_back(1);
  for(int p=1;p<=5000;p++){
    unsigned long long int carry=0;
    for(int i=0; i<power2[p-1].size(); i++)
      power2[p].push_back((power2[p-1][i]<<1)+carry), carry=power2[p][i]/base, power2[p][i]%=base;
    if(carry) power2[p].push_back(carry);
  }
  for(int n; cin>>n; ){
    int len=power2[n].size();
    printf("%llu",power2[n][len-1]);
    for(len-=2;len>=0;len--)
      printf("%018llu",power2[n][len]);
    printf("\n");
  }
}
