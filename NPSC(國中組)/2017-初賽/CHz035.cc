// 簡單模擬，由距離目標最短距離的人決定是順時鐘還是逆時鐘前進，另一個則反向。

#include<iostream>
using namespace std;

pair<int,int> choose[4], decision;
int main(){
  int N, M, Apos, Bpos, Tpos;
  cin>>N>>M>>Apos>>Bpos;
  Apos--, Bpos--;
  while(M--){
    cin>>Tpos;
    choose[0]=(Tpos>Apos)? min( make_pair(Tpos-Apos, 1),make_pair(Apos+N-Tpos,-1) ): min( make_pair(Tpos+N-Apos, 1),make_pair(Apos-Tpos,-1) );
    choose[1]=(Tpos>Bpos)? min( make_pair(Tpos-Bpos, 1),make_pair(Bpos+N-Tpos,-1) ): min( make_pair(Tpos+N-Bpos, 1),make_pair(Bpos-Tpos,-1) );
    if(choose[0].first<choose[1].first)
      Apos=(Apos+choose[0].second+N)%N,
      Bpos=(Bpos-choose[0].second+N)%N;
    else
      Apos=(Apos-choose[1].second+N)%N,
      Bpos=(Bpos+choose[1].second+N)%N;
    cout<<Apos+1<<' '<<Bpos+1<<endl;
  }
}