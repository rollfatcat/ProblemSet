// 數論：XOR的特性 => x^x=0
// 題目要求輸出『無法成對』的數字(map可解)
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  int N
  long x, now=0;

  cin>>N, N--;
  while(N--)
    cin>>x, now^=x;
  cout<<now<<endl;
}