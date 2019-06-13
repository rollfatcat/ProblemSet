#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5;
int N, M;
int vessel[MAXN];

inline bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
bool test(int volumn){
  int remM=M, rem_v=0;
  for(int i=0;i<N;i++){
    if(vessel[i]>rem_v)
      if(remM==0) return false;
      else  rem_v=volumn, remM--;
    rem_v-=vessel[i];
  }
  return true;
}
int main(){
  int caseT;
  scanInt(caseT);
  while(caseT--){
    scanInt(N);
    scanInt(M);

    int nL=0, nR=0, nM;
    for(int i=0;i<N;i++)
      scanInt(vessel[i]),
      nL=max(nL,vessel[i]),
      nR+=vessel[i];
    for(nM=(nL+nR)>>1; nL<nR;){
      nM=(nL+nR)>>1;
      if(test(nM)) nR=nM;
      else nL=nM+1;
    }
    printf("%d\n",nL);
  }
}