// 五則運算(多%，權重和 * / 一樣)
#include<iostream>
#include<sstream>
#include<stack>
#include<map>
using namespace std;

int main(){
  map<char,int>BookP;
  BookP['(']=BookP[')']=0,
  BookP['+']=BookP['-']=1,
  BookP['*']=BookP['/']=BookP['%']=2;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(string line,word; getline(cin,line); ){
    stack<char> stOP;
    stack<long> stNum;
    //
    istringstream iss(line);
    while(iss>>word){
      if(word[0]>='0' and word[0]<='9'){ // 字串是數字推到Stack內
        int num=0;
        for(int i=0;i<word.length();i++)
          num=10*num+word[i]-'0';
        stNum.push(num);
      }else{
        if(word[0]=='(' or stOP.empty() or BookP[word[0]]>BookP[stOP.top()])
          stOP.push(word[0]);
        else if(word[0]==')'){
          for(; stOP.top()!='('; stOP.pop()){
            long x1=stNum.top(); stNum.pop();
            if(stOP.top()=='*') stNum.top()=stNum.top()*x1;
            else if(stOP.top()=='/') stNum.top()=stNum.top()/x1;
            else if(stOP.top()=='%') stNum.top()=stNum.top()%x1;
            else if(stOP.top()=='+') stNum.top()=stNum.top()+x1;
            else if(stOP.top()=='-') stNum.top()=stNum.top()-x1;
          }
          stOP.pop();
        }else{
          for(; !stOP.empty() and BookP[word[0]]<=BookP[stOP.top()]; stOP.pop()){
            long x1=stNum.top(); stNum.pop();
            if(stOP.top()=='*') stNum.top()=stNum.top()*x1;
            else if(stOP.top()=='/') stNum.top()=stNum.top()/x1;
            else if(stOP.top()=='%') stNum.top()=stNum.top()%x1;
            else if(stOP.top()=='+') stNum.top()=stNum.top()+x1;
            else if(stOP.top()=='-') stNum.top()=stNum.top()-x1;
          }
          stOP.push(word[0]);
        }
      }
    }
    // 清空Stack
    for(; !stOP.empty(); stOP.pop()){
      long x1=stNum.top(); stNum.pop();
      if(stOP.top()=='*') stNum.top()=stNum.top()*x1;
      else if(stOP.top()=='/') stNum.top()=stNum.top()/x1;
      else if(stOP.top()=='%') stNum.top()=stNum.top()%x1;
      else if(stOP.top()=='+') stNum.top()=stNum.top()+x1;
      else if(stOP.top()=='-') stNum.top()=stNum.top()-x1;
    }
    cout<<stNum.top()<<endl;
  }
}
// 1314 - 520 / 20 + 530 * 88