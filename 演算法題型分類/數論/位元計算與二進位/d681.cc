/* 題目的輸入格式較為麻煩, 需要注意
 */
#include<iostream>
#include<sstream>
using namespace std;
 
// 把輸入的『二進位字串』轉為『數字』, 題目有保證字串長度5
int StringNum(string ss){ return ((ss[0]-'0')*16)+((ss[1]-'0')*8)+((ss[2]-'0')*4)+((ss[3]-'0')*2)+ss[4]-'0'; }
 
// 把輸入的『數字』轉為『二進位字串』
string NumString(int x){
  string ss="";
  for(int i=0;i<5;i++,x>>=1)
    ss=((x%2)?'1':'0')+ss;
  return ss;
}
 
int main(){
    ios::sync_with_stdio(0),
    cin.tie(0), cout.tie(0);

  string line, word;
  while( getline(cin,line) ){ // 利用getline()讀取到line
    istringstream iss(line); // 將 line 根據空白切割存放到 iss
    iss>>word, cout<<word; // 每次執行 iss>>word 時會把字串放到word
    int num=StringNum(word); // 第一個字串一定是『數字』, 之後是運算符號(AND/OR) 和 數字 交替出現
    while(iss>>word)
      if(word=="or")  cout<<"||", iss>>word, cout<<word, num|=StringNum(word);
      else            cout<<"&&", iss>>word, cout<<word, num&=StringNum(word);
    cout<<" = "<<NumString(num)<<endl;
  }
}
