// 最短化路徑 => 先想辦法讓目前的數字一步變成2^N，若目前已經是2^N時則B=1

#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT, N, B;
  cin>>caseT;
  while(caseT--){
    cin>>N;
    B=1<<__lg(N);
    B=(B==N)? 1: (B<<1)-N;
    cout<<1<<' '<<B<<'\n';
  }
}