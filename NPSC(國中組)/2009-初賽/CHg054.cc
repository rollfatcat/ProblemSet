// 簡單題
#include<iostream>
using namespace std;

int main(){
  int N, M;

  while(cin>>N>>M and N and M){
    N=N%2,  M=M%2,
    cout<<( (N==M)?"Win":"Loss" )<<endl;
  }
}