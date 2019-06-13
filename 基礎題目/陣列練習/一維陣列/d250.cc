// 假九宮格(輸出1-9當中缺少的那個字)
#include<bits/stdc++.h>
using namespace std;

const int maxs=1023;
inline int whereLost(string ss,int nows=0){
  for(int i=0;i<ss.length();i++)
    nows|=1<<(ss[i]-'0');
  return __lg(nows^maxs);
}
int main(){
  string ss;
  while(cin>>ss)
    cout<<whereLost(ss)<<endl;
}