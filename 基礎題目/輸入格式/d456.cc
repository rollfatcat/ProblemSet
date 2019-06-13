// 測資有誤(強迫讀取到字串的最後一個符合的字元才是社辦的位置)
// 練習使用getline
#include<iostream>
using namespace std;

int main(){
  int T;
  for(cin>>T, getchar(); T--; ){
    string ss, as;
    getline(cin,ss), getline(cin,as);
    int Cidx=0,Didx=0;
    for(Cidx=ss.length()-1; Cidx>=0 and ss[Cidx]!=as[0]; Cidx--);
    for(Didx=ss.length()-1; Didx>=0 and ss[Didx]!=as[1]; Didx--);
    if(Cidx>Didx) Cidx^=Didx^=Cidx^=Didx;

    for(int i=0;i<=Cidx;i++) putchar(ss[i]);
    for(int i=Didx;i<ss.length();i++) putchar(ss[i]);
    puts("");
    for(int i=Cidx+1;i<Didx;i++) putchar(ss[i]);
    puts("");
  }
}