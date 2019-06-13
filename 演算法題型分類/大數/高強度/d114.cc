// 算(100!)x(99!)x(98!)x(97!)x...
// 階乘混搭大數乘法
// 需要知道 vector.assign(length,value)的用法
#include<iostream>
#include<vector>
using namespace std;

int main(){

  vector<int>num[2], b, ans[2];
  num[1].push_back(1);
  ans[1].push_back(1);
  for(int N=2, nb;N<=100;N++){
    int now=N%2, pre=!now;
    // 算出 N!
    for(b.clear(), nb=N; nb; nb/=10)
      b.push_back(nb%10);
    int len=num[pre].size()+b.size();
    num[now].assign(len,0);
    for(int i=0;i<num[pre].size();i++)
      for(int j=0;j<b.size();j++)
        num[now][i+j]+=num[pre][i]*b[j];
    for(int i=0, carry=0 ;i<len;i++)
      num[now][i]+=carry, carry=num[now][i]/10, num[now][i]%=10;
    while(num[now].back()==0) num[now].pop_back();
    // 把 N!和ans做大數乘法
    len=ans[pre].size()+num[now].size();
    ans[now].assign(len,0);
    for(int i=0;i<num[now].size();i++)
      for(int j=0;j<ans[pre].size();j++)
        ans[now][i+j]+=num[now][i]*ans[pre][j];
    for(int i=0, carry=0 ;i<len;i++)
      ans[now][i]+=carry, carry=ans[now][i]/10, ans[now][i]%=10;
    while(ans[now].back()==0) ans[now].pop_back();
  }
  // 題目要求輸出每個數字後換行
  for(int i=ans[0].size()-1;i>=0;i--)
    printf("%d\n",ans[0][i]);
}
