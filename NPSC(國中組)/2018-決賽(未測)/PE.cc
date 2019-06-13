// 經典 Nim 的遊戲

#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT, N, K;
  cin>>caseT;
  while(caseT--)
    cin>>N>>K, K++,
    cout<<( (N%K)?"Kitty":"Labrador" )<<endl;
}