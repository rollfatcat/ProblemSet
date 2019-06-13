// 一般的包奘紙換糖果題型(不能借)
#include<iostream>
using namespace std;

int main(){
  for(int n,k,cnt; cin>>n>>k;){
    for(cnt=n; n>=k; )
      cnt+=n/k, n=n/k+n%k;
    cout<<cnt<<endl;
  }
}