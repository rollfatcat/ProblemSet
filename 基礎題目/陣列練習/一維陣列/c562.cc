// 觀察：每個字元中包含圈圈的個數
// 將一堆 if 的判斷方式轉換為對應陣列位置的輸出
#include<iostream>
using namespace std;
int main(){
  int ZeroNum[10]={1,0,0,0,0,0,1,0,2,1};
  int cnt, i;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for(string N; cin>>N; ){
    for(i=0, cnt=0; i<N.length(); i++)
      cnt+=ZeroNum[ N[i]-'0' ];
    cout<<cnt<<endl;
  }
}