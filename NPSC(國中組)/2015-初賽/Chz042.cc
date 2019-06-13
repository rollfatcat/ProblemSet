#include<iostream>
using namespace std;

int main(){
  int target, Apos, Bpos;
  cin>>target>>Apos>>Bpos;
  if(target==Apos) cout<<Bpos<<endl;
  else if(target==Bpos) cout<<Apos<<endl;
  else  cout<<target<<endl;
}