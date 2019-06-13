// (1) 根據題意計算 n! 的0個數
// (2) 觀察可以發現 10=2x5，階乘來說2的個數成長比5的個數快很多 => 0的個數由5的個數決定
//     c661只能透過解法(2)來計算
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 10001
vector<int> lastBit(MaxN);
vector<long> num[2];
int main(){
  lastBit[0]=lastBit[1]=1;
  num[1].push_back(1);
  int base=100000000;
  for(int idx=2;idx<=10000;idx++){
    bool now=idx&1, pre=1^now;
    int carry=0; num[now].clear();
    for(int i=0;i<num[pre].size();i++)
      num[now].push_back(num[pre][i]*idx+carry),  carry=num[now][i]/base,  num[now][i]%=base;
    if(carry) num[now].push_back(carry);
    long tmp;
    for(tmp=0;num[now][tmp]==0;tmp++);
    for(tmp=num[now][tmp];tmp%10==0;tmp/=10);
    lastBit[idx]=tmp%10;
  }
  ios::sync_with_stdio(0), cin.tie(0);
  for(int n;cin>>n;)
    printf("%d -> %d\n",n,lastBit[n]);
}