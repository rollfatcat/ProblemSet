#include<iostream>
using namespace std;

int main(){
    stack<int> st;
  int T, Do;
  cin>>T;
  while(T--){
    cin>>Do;
    switch(Do){
      case 1:
        if(!st.empty())
          st.pop();
        break;
      case 2:
        cout<<st.top()<<endl;
        break;
      case 3:
        cin>>Do;
        st.push(Do);
        break;
      default:
        break;
    }
  }
}