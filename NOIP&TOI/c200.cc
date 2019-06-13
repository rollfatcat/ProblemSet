#include<iostream>
using namespace std;

int main(){
  int T;
  string ss;

  cin>>T;
  while(T--){
    cin>>ss;
    int level=0, len=ss.length();
    for(int i=0;i<len;i++)
      if(ss[i]>'9') level=(36*level+ss[i]-'A'+10)%1688;
      else  level=(36*level+ss[i]-'0')%1688;
    cout<<level+1<<endl;
  }
}