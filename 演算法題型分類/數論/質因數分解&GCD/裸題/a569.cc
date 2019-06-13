// 題目要求的是『連續嚴格遞增』的數列總和
// 數值的範圍高達 1e7 但是測資數量多所以直接建表做O(1)查詢 0.6s
// 找出 sqrt(1e7) 以內的質數判斷的方式時間是 2.4s
#include<bits/stdc++.h>
using namespace std;

const int MAXN=10000001;
bool NotPrime[MAXN]={1,1};

inline char scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c;}
int main(){
  int bound=sqrt(MAXN);
  for(int i=4;i<MAXN;i+=2)
    NotPrime[i]=true;
  for(int i=3;i<bound;i+=2)
    if(NotPrime[i]==0)
      for(int j=3;i*j<MAXN;j+=2)
        NotPrime[i*j]=1;
  char c;
  for(int Prenum,Nownum; (c=scanInt(Prenum))!=EOF; caseN++){
    long sum=(NotPrime[Prenum])?0:Prenum, maxS=sum;
    for(;c!='\n';Prenum=Nownum){
      c=scanInt(Nownum);
      if(NotPrime[Nownum])
        sum=0;
      else
        sum=(Nownum>Prenum)?(sum+Nownum):Nownum,
        maxS=max(maxS,sum);
    }
    printf("%ld\n",maxS);
  }
}