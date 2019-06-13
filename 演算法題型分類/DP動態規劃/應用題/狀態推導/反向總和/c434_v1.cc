// DP解(反向計算) 題目要求算連續3個以上的數字 =>  連續2個以下的數字組合
// 滾動陣列+快速幂次 15ms=>2ms
#include<iostream>
#include<cstring>
using namespace std;
#define mod 1000000007

int DP[1000002][3]={}, power2[1000001]={};
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  int T, N;
  for(cin>>T;T--;){
    cin>>N;
    // matrix
    bool Nnow=1, Bnow=1, Nnxt, Bnxt;
    long v[2][3]={{1,0,0},{}}, m[2][3][3]={{{1,1,1},{1,0,0},{0,1,0}},{}};
    long power2N=1, base2=2; // 2^N mod
    for(int p=N; p>0; p>>=1){
      Bnxt=Bnow,  Bnow=Bnow^1;
      if(p&1){
        power2N=power2N*base2%mod;
        Nnxt=Nnow,  Nnow=Nnow^1;
        v[Nnxt][0]=(m[Bnow][0][0]*v[Nnow][0]+m[Bnow][0][1]*v[Nnow][1]+m[Bnow][0][2]*v[Nnow][2])%mod;
        v[Nnxt][1]=(m[Bnow][1][0]*v[Nnow][0]+m[Bnow][1][1]*v[Nnow][1]+m[Bnow][1][2]*v[Nnow][2])%mod;
        v[Nnxt][2]=(m[Bnow][2][0]*v[Nnow][0]+m[Bnow][2][1]*v[Nnow][1]+m[Bnow][2][2]*v[Nnow][2])%mod;
      }
      base2=base2*base2%mod;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          m[Bnxt][i][j]=(m[Bnow][i][0]*m[Bnow][0][j]+m[Bnow][i][1]*m[Bnow][1][j]+m[Bnow][i][2]*m[Bnow][2][j])%mod;

    }
    // output
    Nnow=1^Nnow;
    long ans=power2N-v[Nnow][0]-v[Nnow][1]-v[Nnow][2];
    while(ans<0)  ans+=mod;
    printf("%ld\n",ans);
  }
}
