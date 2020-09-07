// 觀察規律可以發現很多計算是重覆的，理解之後就可以推出複雜度是O(10000000)可以完成題目要求
#include<iostream>
#include<cstring>
using namespace std;

int SumSOD[10000001]={}; // SumSOD[n]：從1 ~ n 時有幾個是沒有對應到的
int MapSOD[10000063]={}; // MapSOD[n]：對應到 n 時最小的i值 i+SOD(i)
int func(int a,int b){ return SumSOD[b]-SumSOD[a-1]; }
int func(int a){ return MapSOD[a]; }
inline bool scanInt(int &x){
  char c; for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');
  return c==' ';
}
int main(){
  memset(MapSOD,0xff,sizeof(MapSOD));
  for(int i=1;i<=10000000;i++){
    int SODi=i;
    for(int j=i;j;j/=10)
      SODi+=j%10;
    if(MapSOD[ SODi ]==-1) MapSOD[ SODi ]=i;
    SumSOD[i]=SumSOD[i-1]+(MapSOD[i]<0);
  }
  int T,a,b;
  scanInt(T);
  for(int caseN=1; caseN<=T; caseN++){
    if(scanInt(a))
      scanInt(b),
      printf("Case %d: %d\n",caseN,func(a,b));
    else
      printf("Case %d: %d\n",caseN,func(a));
  }
}