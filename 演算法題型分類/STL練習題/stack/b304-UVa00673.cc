// 不能只是比對數量, 右邊測資要輸出"No"： ([)]
#include<iostream>
#include<stack>
using namespace std;

int main(){
  int T, i;
  string ss;

  for(cin>>T, getchar(); T--;){
    getline(cin,ss);
    stack<char> S;
    for(i=0; i<ss.length(); i++)
      if(ss[i]=='(' or ss[i]=='[')
        S.push(ss[i]);
      else if(ss[i]==')'){
        if(!S.empty() and S.top()=='(')  S.pop();
        else break;
      } else if(ss[i]==']'){
        if(!S.empty() and S.top()=='[')  S.pop();
        else break;
      }
    if(i==ss.length() and S.empty())  cout<<"Yes\n";
    else   cout<<"No\n";
  }
}