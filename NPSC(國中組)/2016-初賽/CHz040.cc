#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, Ns=0, Ne=0, Ppre=-1;
  string ss;
  cin>>N>>ss;
  for(int i=0;i<ss.length();i++)
    (ss[i]=='s')? Ns++: Ne++;
  if(Ne>Ns) // 若最後的e個數一定會多餘s個數，代表永遠無法達成要求
    cout<<-1<<endl;
  else{ // 可達成要求時則在某個時間點時會造成『不合法』狀態的前Ｎ個子字串移到後面
    N=Ns=Ne=0;
    for(int i=0;i<ss.length();i++){
      (ss[i]=='s')? Ns++: Ne++;
      if(Ne>Ns){
        N+=i-Ppre;
        Ns=Ne=0;
        Ppre=i;
      }
    }
    cout<<N<<'\n';
  }
}
/*
8
seeseess
*/