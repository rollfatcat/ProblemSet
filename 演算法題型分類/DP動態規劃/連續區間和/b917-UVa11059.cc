// 連續區間最大『乘積』(找不到正數區間時輸出0)
// 窮舉所有的起點和結尾
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, num[18];
  for(int caseN=1; cin>>N; caseN++){
    long Maxmul=0;
    for(int i=0; i<N; i++)
      cin>>num[i];
    for(int st=0;st<N;st++){
      long mul=1;
      for(int ed=st;ed<N;ed++){
        mul*=num[ed];
        if(Maxmul<mul)
          Maxmul=mul;
      }
    }
    cout<<"Case #"<<caseN<<": The maximum product is "<<Maxmul<<"."<<endl<<endl;
  }
}