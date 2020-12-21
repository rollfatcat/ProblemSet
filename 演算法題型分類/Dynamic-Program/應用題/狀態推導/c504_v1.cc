// DP解+滾動陣列(記憶體大小限制) => 線性推導第4筆測資會TLE => 矩陣的快速算法
#include<iostream>
using namespace std;
#define mod 1000000007

int main(){

  int caseNum, N;
  for(cin>>caseNum; caseNum--; ){
    cin>>N;
    long nowS[2][2];
    nowS[1][0]=1, nowS[1][1]=4;
    for(int now=2; now<=N; now++)
      nowS[now%2][0]= nowS[ (now-1)%2 ][1],
      nowS[now%2][1]=(nowS[ (now-1)%2 ][0]+nowS[ (now-1)%2 ][1]<<2 )%mod;
    cout<<(nowS[N%2][0]+nowS[N%2][1])%mod<<endl;
  }
}