// 字串位置練習, 題目的輸入的位置是從1開始算
#include<iostream>
using namespace std;

int main(){
  string s1, s2;
  int n1, n2;

  while(cin>>n1>>n2 and n1){
    s1="";
    for(int i=0;i<n1;i++)
      cin>>s2,  s1+=s2;
    s2="";
    for(int i=0;i<n2;i++)
      cin>>n1,  s2+=s1[n1-1];
    cout<<s2<<endl;
  }
}