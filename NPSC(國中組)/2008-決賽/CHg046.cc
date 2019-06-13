// 練習 cstring的substr用法
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  string op, ss, tmp;
  int a, b;

  cin>>ss;
  while(cin>>op){
    if(op=="END")
      break;
    else if(op=="ADD")
      cin>>tmp, ss=ss+tmp;
    else if(op=="ADH")
      cin>>tmp, ss=tmp+ss;
    else if(op=="ERA") //一個參數代表從這裡開始, 兩個參數的第二個代表擷取的字串長度
      cin>>a>>b, ss=ss.substr(0,a-1)+ss.substr(b);
    else if(op=="SUB")
      cin>>a>>b, ss=ss.substr(a-1,b-a+1);
    else if(op=="SPA")
      cin>>a, ss=ss.substr(0,a-1)+'_'+ss.substr(a-1);
    cout<<ss<<endl;
  }
}