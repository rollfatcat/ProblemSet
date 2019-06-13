#include<iostream>
#include<stack>
using namespace std;

int main(){
  string ss;
  int num;
  // 確定ASCII code
  //cout<<int('+')<<' '<<int('-')<<' '<<int('*')<<' '<<int('/')<<' '<<int('%')<<endl;

  // 輸入包含空白字元, getline() 讀取直到'\n'
  while( getline(cin,ss) and ss!=""){
    stack<int> st;
    for(int i=0;i<ss.length(); i++)
      if(ss[i]>='0'){
        num=ss[i++]-'0';
        while(i<ss.length() and ss[i]>='0')
          num=num*10+(ss[i++]-'0');
        st.push(num);
      } else {
        num=st.top();
        st.pop();
        if(ss[i]=='+')
          num=st.top()+num;
        else if(ss[i]=='-')
          num=st.top()-num;
        else if(ss[i]=='*')
          num=st.top()*num;
        else if(ss[i]=='/')
          num=st.top()/num;
        else if(ss[i]=='%')
          num=st.top()%num;
        st.pop();
        st.push(num);
        i++;
      }

    cout<<st.top()<<endl;
  }
}