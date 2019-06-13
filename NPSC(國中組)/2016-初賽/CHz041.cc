#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int Y, M, D, X, T;
  cin>>Y>>M>>D>>X>>T;
  bool NotWeekend=(0<X%7 and X%7<6);
  cout<<( (NotWeekend xor T)? "unhappy": "happy" )<<'\n';
}