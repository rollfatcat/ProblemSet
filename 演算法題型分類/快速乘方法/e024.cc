// 極限測資(根據輸入的範圍最大是1e5，所以MOD是1e6) => 2.5s
// 極限測資(1e5,1e5)最大長度是83334，加速的話計算型態可以改為__int128但必需自已寫輸出
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const long MOD=1e6;
vector<long> Bnum[2], Nnum[2];
int Blen[2], Nlen[2];
int main(){

  for(int Bn,Pn; scanf("%d %d",&Bn,&Pn) and Bn;){

    Bnum[0].assign(1,Bn),
    Nnum[0].assign(1,1),
    Blen[0]=Nlen[0]=1;

    bool Bnow=0, Bnxt=1, Nnow=0, Nnxt=1;
    for(; true; Bnow=Bnxt,Bnxt^=1){
      if(Pn&1){
        Nlen[Nnxt]=Nlen[Nnow]+Blen[Bnow];
        Nnum[Nnxt].clear(),
        Nnum[Nnxt].resize(Nlen[Nnxt]);
        for(int i=0; i<Nlen[Nnow]; i++)
          for(int j=0; j<Blen[Bnow]; j++)
            Nnum[Nnxt][i+j]+=(Nnum[Nnow][i]*Bnum[Bnow][j]);
        long carry=0;
        for(int i=0;i<Nlen[Nnxt];i++)
          Nnum[Nnxt][i]+=carry,
          carry=Nnum[Nnxt][i]/MOD,
          Nnum[Nnxt][i]%=MOD;
        for(Nlen[Nnxt]--; Nlen[Nnxt]>=0 and Nnum[Nnxt][Nlen[Nnxt]]==0; Nlen[Nnxt]--);
        Nlen[Nnxt]++;
        Nnow=Nnxt, Nnxt^=1;
      }
      Pn>>=1;
      if(Pn==0) break;
      // 底數相乘
      Blen[Bnxt]=Blen[Bnow]<<1;
      Bnum[Bnxt].clear(),
      Bnum[Bnxt].resize(Blen[Bnxt]);
      for(int i=0; i<Blen[Bnow]; i++)
        for(int j=0; j<Blen[Bnow]; j++)
          Bnum[Bnxt][i+j]+=Bnum[Bnow][i]*Bnum[Bnow][j];
      long carry=0;
      for(int i=0; i<Blen[Bnxt]; i++)
        Bnum[Bnxt][i]+=carry,
        carry=Bnum[Bnxt][i]/MOD,
        Bnum[Bnxt][i]%=MOD;
      for(Blen[Bnxt]--; Bnum[Bnxt][Blen[Bnxt]]==0;Blen[Bnxt]--);
      Blen[Bnxt]++;
    }
    printf("%ld",Nnum[Nnow][Nlen[Nnow]-1]);
    for(int i=Nlen[Nnow]-2; i>=0; i--)
      printf("%06ld",Nnum[Nnow][i]);
    puts("");
  }
}