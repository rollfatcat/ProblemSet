#include<iostream>
using namespace std;

int main(){
  string ss;
  while(cin>>ss){
    for(int idx=0;idx<ss.length();){
      int pre=idx;
      char c=ss[idx++];
      while(c==ss[idx])
        idx++;
      int num=idx-pre;
      if(num>2) cout<<num<<c;
      else if(num==2) cout<<c<<c;
      else cout<<c;
    }
    cout<<endl;
  }
}