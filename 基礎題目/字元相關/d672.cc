// 需要說明清楚題目的9-degree定義
// 練習遞迴的寫法
#include<bits/stdc++.h>
using namespace std;

int recursive(int x,int sum=0){
  if(x==9)  return 1;
  while(x)
    sum+=x%10, x/=10;
  return recursive(sum)+1;
}
int main(){
  string ss;
  while(cin>>ss and ss[0]>'0'){
    int sum=0;
    for(int i=0;i<ss.length();i++)
      sum+=ss[i]-'0';
    int p=(sum%9)? 0: recursive(sum);
    if(p==0) cout<<ss<<" is not a multiple of 9.\n";
    else cout<<ss<<" is a multiple of 9 and has 9-degree "<<p<<".\n";
  }
}