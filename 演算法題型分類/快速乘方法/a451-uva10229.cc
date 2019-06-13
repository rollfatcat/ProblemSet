// Fib的快速幂次，輸出 A0且要取mod，注意mod最大是(1<<19)，相加時可能會超過int範圍要改成long
// 0 1 1 2 3 5 8 ...
#include<iostream>
using namespace std;

int main(){
  cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int mod[20], n, m;
  for(int i=0;i<20;i++)
    mod[i]=1<<i;

  while(cin>>n>>m){
    long base[2][2][2]={ {{1,1},{1,0}}, {} }, st[2][2]={{1,0},{}};
    bool nowB=0, nxtB, nowS=0, nxtS;
    for(;n>0; n/=2){
      if(n%2){
        nxtS=nowS^1;
        st[nxtS][0]=(base[nowB][0][0]*st[nowS][0]+base[nowB][0][1]*st[nowS][1])%mod[m];
        st[nxtS][1]=(base[nowB][1][0]*st[nowS][0]+base[nowB][1][1]*st[nowS][1])%mod[m];
        nowS=nxtS;
      }
      nxtB=nowB^1;
      base[nxtB][0][0]=(base[nowB][0][0]*base[nowB][0][0]+base[nowB][0][1]*base[nowB][1][0])%mod[m];
      base[nxtB][0][1]=(base[nowB][0][0]*base[nowB][0][1]+base[nowB][0][1]*base[nowB][1][1])%mod[m];
      base[nxtB][1][0]=(base[nowB][1][0]*base[nowB][0][0]+base[nowB][1][1]*base[nowB][1][0])%mod[m];
      base[nxtB][1][1]=(base[nowB][1][0]*base[nowB][0][1]+base[nowB][1][1]*base[nowB][1][1])%mod[m];
      nowB=nxtB;
    }
    cout<<st[nowS][1]<<endl;
  }
}