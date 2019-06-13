// sstream的 istringstream的根據空白切開字串練習
#include<iostream>
#include<sstream>
using namespace std;

int StringNum(string ss){ return ((ss[0]-'0')<<4)+((ss[1]-'0')<<3)+((ss[2]-'0')<<2)+((ss[3]-'0')<<1)+ss[4]-'0'; }
string NumString(int x){
  string ss="";
  for(int i=0;i<5;i++,x>>=1)
    ss=((x&1)?'1':'0')+ss;
  return ss;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string line, word;
  while( getline(cin,line) ){
    istringstream iss(line);
    iss>>word, cout<<word;
    int num=StringNum(word);
    while(iss>>word)
      if(word=="or")  cout<<"||", iss>>word, cout<<word, num|=StringNum(word);
      else            cout<<"&&", iss>>word, cout<<word, num&=StringNum(word);
    cout<<" = "<<NumString(num)<<endl;
  }
}