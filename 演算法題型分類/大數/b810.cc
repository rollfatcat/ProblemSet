// 本質是快速冪次和單個位數的大數乘法(須知道巴卡三角形係數的特性)
/* 第一次看到會直覺是對應項乘以巴斯卡三角形的係數項，但是係數項成長得很快需要大數紀錄
 * 仔細觀察可以知道巴斯卡三角形係數是對稱的而對應項的數字和加起來都相同
 * 而剛好巴斯卡第N列的三角形係數總和=2^(N-1)可以推導出第 N 項的數值和 = (N+1)/2*(2^(N-1))
 */
#include<iostream>
#include<vector>
using namespace std;
#define base 1000000000

int main(){
  vector<long> power2[2016];
  power2[0].push_back(1),
  power2[1].push_back(2);
  for(int idx=2;idx<2016;idx++){
    long carry=0;
    for(int i=0;i<power2[idx-1].size();i++)
      power2[idx].push_back( (power2[idx-1][i]<<1)+carry ),
      carry=power2[idx].back()/base,
      power2[idx].back()%=base;
    if(carry) power2[idx].push_back(carry);
  }

  ios::sync_with_stdio(0),cin.tie(0);

  for(int N; cin>>N;){
    if(N==1){ printf("1\n"); continue; }
    vector<long> ans;
    long carry=0;
    for(int i=0;i<power2[N-2].size();i++)
      ans.push_back( (N+1)*power2[N-2][i]+carry ),
      carry=ans.back()/base,
      ans.back()%=base;
    if(carry) ans.push_back(carry);
    // 輸出
    printf("%ld",ans.back());
    for(int i=ans.size()-2;i>=0;i--)
      printf("%09ld",ans[i]);
    printf("\n");
  }
}