// 解題關鍵：相似三角形，兩中點的連線剛好是底邊邊長的一半
// 溝通難度的定義是兩終點連線邊長的兩倍＝底邊長度

#include<iostream>
using namespace std;

int main(){
  int A, B, C;
  while(cin>>A>>B>>C)
    cout<<A+B+C<<endl;
}