/* 一個圓將平面分割成「圓內」和「圓外」= 2個區域，每交一個圓會多兩個區域
 * A(1)=2
 * A(2)=A(1)+2x1
 * A(3)=A(2)+2x2
 * A(n)=A(n-1)+2x(n-1)=...=2+nx(n-1)
 */
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  for(int N; cin>>N;)
    printf("%d\n",2+N*(N-1));
}