#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT, N, M, K;
  cin>>caseT;
  while(caseT--)
    cin>>N>>M>>K,
    cout<<( M/N+(M%N>=K) )<<'\n';
}