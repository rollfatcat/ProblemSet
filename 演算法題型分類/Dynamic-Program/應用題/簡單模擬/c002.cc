#include<iostream>
using namespace std;

int f91(int n){
  return (n>=101)?(n-10):( f91(f91(n+11)) );
}
int main(){
  int N;

  while(cin>>N and N){
    cout<<"f91("<<N<<") = "<<f91(N)<<endl;
  }
}