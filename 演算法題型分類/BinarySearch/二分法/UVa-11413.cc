// 二分搜尋應用題型(2) : 利用二分搜尋快速逼近答案
/* 給定N個牛奶瓶子，以及M個容器，每個牛奶瓶子n[i]的容積不一樣(題目會給)，
 * 我們所要求的是一個"容器"的容積至少要"多少"才能使得只用'M'個就能把那N個牛奶瓶裝完，
 * 而裝的時候有幾個規則：第一個牛奶瓶倒入容器後才能換第二個，每個牛奶瓶只能到入同個容器
 * (因此如果該容器還有空間但不夠裝完這個牛奶瓶的話，就只能換下個容器)。
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e3;
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
  while(scanInt(N) and scanInt(M)){
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