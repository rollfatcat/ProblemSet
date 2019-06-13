// 喬瑟夫問題變形，給定總人數和最後一個活下來的號碼，詢問最少的skip可以讓最後一個號碼和輸入的一樣
// 第一個掛掉的號碼固定是1號，0ms估計是用DP的方式測出來的
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int n,m,last; cin>>n>>last and n;){
    vector<int> num(n);
    for(m=2; num[0]!=last; m++){
      num.resize(n);
      for(int i=0;i<n;i++)
        num[i]=i+1;
      for(int kill=0; num.size()>1; kill=(kill+m-1)%num.size())
        num.erase(num.begin()+kill);
    }
    cout<<m-1<<'\n';
  }
}