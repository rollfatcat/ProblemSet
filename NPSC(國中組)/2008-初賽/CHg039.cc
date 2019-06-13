// 簡單的 if else
#include<iostream>
using namespace std;

int main(){
  int caseNum, a, b, c;

  cin>>caseNum;
  while(caseNum--){
    cin>>a>>b>>c;
    if(a!=b and b!=c and a!=c)  cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
  }
}