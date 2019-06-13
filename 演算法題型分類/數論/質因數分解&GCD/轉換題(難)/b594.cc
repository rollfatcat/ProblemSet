/* 題目要求是當他吃了 k 單位，下一個只會吃 k+1 單位
 * 主人有 N-1 份食物，剛好是從 1 ~ N-1 單位，要用這些餵狗一共 N 單位
 * 狗至少要吃 2 份，而且他只能吃下小於 N 單位的食物
 * 所有食物都是正整數，求餵法有幾種
 */
 // 做法等同 a471/d756，找出所有的奇數因數的個數
#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<bool> isP(1001,1);
  for(int i=4;i<=1000;i+=2)
    isP[i]=0;
  for(int i=3;i<=31;i+=2)
    if(isP[i])
      for(int k=i<<1,j=k+i; j<=1000; j+=k)
        isP[j]=0;
  vector<int> prime;
  prime.push_back(2);
  for(int i=3;i<=1000;i+=2)
    if(isP[i])
      prime.push_back(i);
  // 關鍵：只計算質因數所構成的因數個數，即累乘(各個質因數的次方項+1)
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int x; cin>>x and x; ){
    int cnt=1;
    for(int i=1;i<prime.size() and prime[i]*prime[i]<=x;i++){
      int p=0;
      for(; x%prime[i]==0; x/=prime[i],p++);
      cnt*=(p+1);
    }
    if(x%2==0 and x>1) cnt<<=1;
    cout<<cnt-1<<'\n';
  }
}