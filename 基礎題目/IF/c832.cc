// 水題：只有當三組都一樣時才輸出"No"不然都是"Yes"
#include<iostream>
using namespace std;

int main(){
  int T, num[6];

  for(cin>>T; T--; ){
    cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]>>num[5];
    bool same=true;
    same&=( (num[0]==num[2] and num[1]==num[3]) or (num[1]==num[2] and num[0]==num[3]));
    same&=( (num[0]==num[4] and num[1]==num[5]) or (num[1]==num[4] and num[0]==num[5]));
    if(same) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
  }
}
