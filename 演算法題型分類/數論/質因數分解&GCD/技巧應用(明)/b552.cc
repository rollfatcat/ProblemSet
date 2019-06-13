// 需要判斷任意10位數是不是質數 => 注意建表時範圍
#include<iostream>
#include<vector>
using namespace std;

vector<bool> isP(100000,true);
vector<int> prime;
vector<long> p2;
bool Check(long x){
  if(x<100000)  return isP[x];
  int i=0;
  for(; p2[i]<x and x%prime[i]; i++);
  return p2[i]>x;
}
int main(){
  // 質數表
  isP[0]=isP[1]=false;
  for(int i=4;i<100000;i+=2)
    isP[i]=false;
  for(int i=3;i<=316;i++)
    if(isP[i])
      for(int k=i<<1, j=i+k;j<100000;j+=k)
        isP[j]=false;
  for(int i=2;i<100000;i++)
    if(isP[i])
      prime.push_back(i), p2.push_back(i*i);
    p2.push_back(10000000000);
  //
  for(char ss[11]; scanf("%s",ss)!=EOF; ){
    int cnt=0;
    long num=0;
    vector<long> ans;
    for(int i=0; i<10;i++){
      num=num*10+ss[i]-'0';
      if(Check(num))
        ans.push_back(num), num=0;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
      cout<<ans[i]<<endl;
    cout<<endl;
  }
}