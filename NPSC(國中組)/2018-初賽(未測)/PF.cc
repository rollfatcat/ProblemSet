// 麻將牌形判斷：國士無雙13聽 / 國士無雙單聽 / 都不是
#include<iostream>
#include<map>
using namespace std;

int main(){
  string one;
  map<string,short> memo;
  memo["1m"]=0, memo["1p"]=0, memo["1s"]=0,
  memo["9m"]=0, memo["9p"]=0, memo["9s"]=0,
  memo["1z"]=0, memo["2z"]=0, memo["3z"]=0, memo["4z"]=0, memo["5z"]=0, memo["6z"]=0, memo["7z"]=0;

  bool Neither=false;
  bool IsThreeteen=false;
  for(int i=1;i<=13;i++){
    cin>>one;
    Neither|=(memo.find(one)==memo.end());
    if(!Neither){
      IsThreeteen|=(memo[one]);
      memo[one]++;
    }
  }
  if(Neither) cout<<0<<endl;
  else cout<<((!IsThreeteen)?13:1)<<endl;
}