// 題目只保證給予 1e5 個數字且範圍落在 int 以內(測資的數字含有負數) => 離散化
// 逆數對的計算：CDQ解
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+1;
int org[MAXN], ord[MAXN];
inline bool scanInt(int &x){
  char c=getchar();
  bool sign=(c=='-');
  for(x=(sign)?0:(c-'0');(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  if(sign) x=-x;
  return c!=EOF;
}
long CDQ(int nL,int nR){
  if(nL==nR) return 0;
  int nM=(nL+nR)>>1;
  long out=CDQ(nL,nM)+CDQ(nM+1,nR);
  int iL=nL, iR=nM+1, iK=nL;
  while(iL<=nM and iR<=nR)
    if(org[iL]>org[iR])
      ord[iK++]=org[iR++],
      out+=nM-iL+1;
    else
      ord[iK++]=org[iL++];
  while(iL<=nM) ord[iK++]=org[iL++];
  while(iR<=nR) ord[iK++]=org[iR++], out+=nM-iL+1;
  for(int i=nL;i<=nR;i++) org[i]=ord[i];
  return out;
}
int main(){
  for(int N,caseN=1; scanInt(N) and N;caseN++){
    for(int i=0;i<N;i++)
      scanInt(org[i]);
    printf("Case #%d: %ld\n",caseN,CDQ(0,N-1));
  }
}
/*
5
2 1 5 4 3
=====
4
*/