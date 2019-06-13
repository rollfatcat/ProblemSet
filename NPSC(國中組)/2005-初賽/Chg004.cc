#include<iostream>
using namespace std;

int main(){
  string org="ABCDEFGHIJKLMNOPQRSTUVWXYZ", ss, shift;
  int caseNum, x;

  cin>>caseNum;
  while(caseNum--){
    cin>>x>>ss;
    shift=org.substr(26-x)+org.substr(0,26-x);
    for(int i=0;i<ss.length();i++)
      cout<<shift[ss[i]-'A'];
    cout<<endl;
  }
}