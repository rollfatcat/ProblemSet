// Stack 經典問題(需搭配圖解說明)
#include<iostream>
#include<stack>
using namespace std;

int main(){
  string msg;
  int num, input, A_now;
  bool flag;
  for(int caseNum=0;cin>>num and num;caseNum++){
    if(caseNum) cout<<endl;
    while(cin>>input and input){
      flag=true;
      stack<int> st;
      for(int i=1;i<input;i++)
        st.push(i);
      A_now=input+1;
      for(int i=1;i<num;i++){
        cin>>input;
        if(flag){
          if(st.empty() or input>st.top()){
            for(int i=A_now;i<input;i++)
              st.push(i);
            A_now=input+1;
          }
          else if(input==st.top())
            st.pop();
          else
            flag=false;
        }
      }
      msg=(flag)?"Yes":"No";
      cout<<msg<<endl;
    }
  }
}