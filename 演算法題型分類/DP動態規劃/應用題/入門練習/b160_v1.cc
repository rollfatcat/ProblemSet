#include<iostream>
using namespace std;

int main(){
  int M, S, T, preDP=0, preJump=0;

  cin>>M>>S>>T;
  for(int i=1;i<=T;i++){
    preDP+=17;
    preJump+=((M>=10)?60:0);
    M+=((M>=10)?-10:4);
    preDP=max(preDP,preJump);
    if(preDP>=S){
      cout<<"Yes"<<endl<<i<<endl; return 0;
    }
  }
  cout<<"No"<<endl<<preDP<<endl;
}