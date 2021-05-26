// 四則運算練習
#include<iostream>
#include<sstream>
#include<stack>
#include<map>
using namespace std;

int main(){
  map<char,int>BookP;
  BookP['(']=BookP[')']=0,
  BookP['+']=BookP['-']=1,
  BookP['*']=BookP['/']=2;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int T;
  for(cin>>T; T--;){
    string line;
    cin>>line;
    stack<char> stOP;
    stack<long> stNum;
    //
    int num=0;
    for(int i=0; i<line.length(); i++){
      if(line[i]>='0' and line[i]<='9') // 字串是數字推到Stack內
        num=10*num+line[i]-'0';
      else{
        if(num>0) stNum.push(num), num=0;
        if(line[i]=='(' or stOP.empty() or BookP[line[i]]>BookP[stOP.top()])
          stOP.push(line[i]);
        else if(line[i]==')'){
          for(; stOP.top()!='('; stOP.pop()){
            long x1=stNum.top(); stNum.pop();
            if(stOP.top()=='*') stNum.top()=stNum.top()*x1;
            else if(stOP.top()=='/') stNum.top()=stNum.top()/x1;
            else if(stOP.top()=='+') stNum.top()=stNum.top()+x1;
            else if(stOP.top()=='-') stNum.top()=stNum.top()-x1;
          }
          stOP.pop();
        }else{
          for(; !stOP.empty() and BookP[line[i]]<=BookP[stOP.top()]; stOP.pop()){
            long x1=stNum.top(); stNum.pop();
            if(stOP.top()=='*') stNum.top()=stNum.top()*x1;
            else if(stOP.top()=='/') stNum.top()=stNum.top()/x1;
            else if(stOP.top()=='+') stNum.top()=stNum.top()+x1;
            else if(stOP.top()=='-') stNum.top()=stNum.top()-x1;
          }
          stOP.push(line[i]);
        }
      }
    }
    // 清空數字的部分
    if(num>0) stNum.push(num);
    // 清空Stack
    for(; !stOP.empty(); stOP.pop()){
      long x1=stNum.top(); stNum.pop();
      if(stOP.top()=='*') stNum.top()=stNum.top()*x1;
      else if(stOP.top()=='/') stNum.top()=stNum.top()/x1;
      else if(stOP.top()=='+') stNum.top()=stNum.top()+x1;
      else if(stOP.top()=='-') stNum.top()=stNum.top()-x1;
    }
    cout<<stNum.top()<<endl;
  }
}
// 1314-520/20+530*88