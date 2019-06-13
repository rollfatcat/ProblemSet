// 從一堆字元中撈出『數字』字串
// 練習使用 getline
#include<iostream>
using namespace std;

int main(){
  unsigned int len=0, num[2];
  for(string ss; len<2; ){
    getline(cin,ss);
    for(int i=0;i<ss.length(); )
      if('0'<=ss[i] and ss[i]<='9'){
        for(num[len]=ss[i++]-'0'; i<ss.length() and '0'<=ss[i] and ss[i]<='9'; i++)
          num[len]=10*num[len]+ss[i]-'0';
        len++;
      } else i++;
  }
  cout<<num[0]<<' '<<num[1]<<' '<<(num[0]+num[1])<<endl;
}