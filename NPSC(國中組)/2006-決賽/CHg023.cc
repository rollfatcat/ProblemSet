// 平方和
#include<iostream>
using namespace std;

int main(){
  int n, x, sum;

  while(cin>>n and n){
    for(sum=0;n--;)
      cin>>x, sum+=(x*x);
    cout<<sum<<endl;
  }
}