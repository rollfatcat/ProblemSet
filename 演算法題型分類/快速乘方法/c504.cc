// DP解+快速幕次(記憶體大小限制)
#include<iostream>
using namespace std;

int main(){

  int caseNum, N, mod=1000000007;
  for(cin>>caseNum; caseNum--; ){
    cin>>N, N--;
    long base[2][2][2]={ {{0,1},{4,4}}, {} }, st[2][2]={{1,4},{}};
    bool nowB=0, nxtB, nowS=0, nxtS;
    for( ;N>0; N/=2){
      if(N%2){
        nxtS=nowS^1;
        st[nxtS][0]=(base[nowB][0][0]*st[nowS][0]+base[nowB][0][1]*st[nowS][1])%mod;
        st[nxtS][1]=(base[nowB][1][0]*st[nowS][0]+base[nowB][1][1]*st[nowS][1])%mod;
        nowS=nxtS;
      }
      nxtB=nowB^1;
      base[nxtB][0][0]=(base[nowB][0][0]*base[nowB][0][0]+base[nowB][0][1]*base[nowB][1][0])%mod;
      base[nxtB][0][1]=(base[nowB][0][0]*base[nowB][0][1]+base[nowB][0][1]*base[nowB][1][1])%mod;
      base[nxtB][1][0]=(base[nowB][1][0]*base[nowB][0][0]+base[nowB][1][1]*base[nowB][1][0])%mod;
      base[nxtB][1][1]=(base[nowB][1][0]*base[nowB][0][1]+base[nowB][1][1]*base[nowB][1][1])%mod;
      nowB=nxtB;
    }
    cout<<(st[nowS][0]+st[nowS][1])%mod<<endl;
  }
}