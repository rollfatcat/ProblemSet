// 不需要任何加入技巧
// 0 1 1 2 3
#include<iostream>
using namespace std;

int cnt;
int Fib(int now){
  cnt++;
  if(now==0)  return 0;
  if(now==1)  return 1;
  return Fib(now-1)+Fib(now-2);
}
int main(){
  int N;
  while(cin>>N){
    cnt=0;
    int t=Fib(N);
    cout<<t<<' '<<cnt<<endl;
  }
}