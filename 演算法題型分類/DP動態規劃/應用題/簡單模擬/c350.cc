// 空酒瓶換酒問題, 給整數(不是轉換率)
#include<iostream>
using namespace std;

int main(){
  int rem, cnt, newN;
  for(int N, K, W; cin>>N>>K>>W; ){
    for(cnt=N, rem=N; rem>=K;)
      newN=(rem/K)*W,
      cnt+=newN,
      rem=rem%K+newN;
    cout<<cnt<<endl;
  }
}