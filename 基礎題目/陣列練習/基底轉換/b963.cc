// 題目會給兩個不同進位制的數字，要求輸出總和(以題目給的數字為基底)
// 不同進位制間的相互轉換

#include<bits/stdc++.h>
using namespace std;

inline int CharInt(char c){
  if(c<='9') return c-'0';
  if(c>='a') return c-'a'+10;
  return c-'A'+10;
}
inline int StrNum(int base,string ss,int out=0){
  for(int i=0;i<ss.length();i++)
    out=out*base+CharInt(ss[i]);
  return out;
}
int main(){
  string word="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string ss;
  int base, Num;
  while(cin>>base>>ss){
    Num=StrNum(base,ss);
    cin>>base>>ss;
    Num+=StrNum(base,ss);
    cin>>base;
    for(ss="";Num;Num/=base)
      ss=word[Num%base]+ss;
    cout<<ss<<'\n';
  }
}