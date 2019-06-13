// 字串比對大小
#include<iostream>
using namespace std;

bool compare(string s1, string s2){
  if(s2.length()==s1.length())
    for(int i=0;i<s2.length();i++)
      if(s2[i]!=s1[i])
        return s2[i]>s1[i];
  return s2.length()>=s1.length();
}
int main(){
  string s1, s2;

  while(cin>>s1>>s2){
    if(s1=="0" and s2=="0")
      break;
    if(compare(s1,s2))  cout<<"Fair"<<endl;
    else cout<<"Unfair"<<endl;
  }
}