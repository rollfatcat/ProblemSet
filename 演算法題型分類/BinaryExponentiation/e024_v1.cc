// __int128版本(0.9s，base=1e17)
// __int128可支援到1e38的大小，用來反推base
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const __int128 MOD=1e17;
vector<__int128> Bnum[2], Nnum[2];
int Blen[2], Nlen[2];
void PrintInt128(__int128 x){
  char ss[17];
  int L=16;
  for(;L>=0;L--,x/=10)
      ss[L]=(x%10+'0');
  for(L=0;L<17;L++)
    putchar(ss[L]);
}
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
        __int128 carry=0;
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
      __int128 carry=0;
      for(int i=0; i<Blen[Bnxt]; i++)
        Bnum[Bnxt][i]+=carry,
        carry=Bnum[Bnxt][i]/MOD,
        Bnum[Bnxt][i]%=MOD;
      for(Blen[Bnxt]--; Bnum[Bnxt][Blen[Bnxt]]==0;Blen[Bnxt]--);
      Blen[Bnxt]++;
    }
    //
    __int128 x=Nnum[Nnow][Nlen[Nnow]-1];
    char ss[17];
    int L=0;
    for(;L<17 and x;L++,x/=10)
      ss[L]=(x%10+'0');
    while(L--)
      putchar(ss[L]);
    for(int i=Nlen[Nnow]-2; i>=0; i--)
      PrintInt128(Nnum[Nnow][i]);
    puts("");
  }
}