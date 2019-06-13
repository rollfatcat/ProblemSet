// 題目會給字串，要在其中挑出數字和運算符號並算出計算結果
// 字元處理+簡單四則計算
#include<iostream>
#include<cstring>
using namespace std;

int main(){
  char ss[10000], sym;

  for(int N, i; cin>>N;)
    while(N--){
      scanf("%s",ss);
      long A=0, B=0;
      for(i=0;i<strlen(ss);i++)
        if('0'<=ss[i] and ss[i]<='9')
          A=10*A+ss[i]-'0';
        else if(ss[i]=='+' or ss[i]=='-' or ss[i]=='*' or ss[i]=='/' or ss[i]=='%'){
          sym=ss[i]; break;
        }
      for(i++;i<strlen(ss);i++)
        if('0'<=ss[i] and ss[i]<='9')
          B=10*B+ss[i]-'0';
      if(sym=='+') cout<<A+B<<endl;
      else if(sym=='-')  cout<<A-B<<endl;
      else if(sym=='*')  cout<<A*B<<endl;
      else if(sym=='/')  cout<<A/B<<endl;
      else  cout<<A%B<<endl;
    }
}