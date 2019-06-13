// 題目給一個Ｎ，輸出 (1<<(N+1))-1 的數字 => 大數乘法處理
#include<bits/stdc++.h>
using namespace std;

const long base=1e17;
struct BigInt{
  int len=0;
  long digit[20]={};
  BigInt(){ }
  BigInt(int x){ digit[len++]=x; }

  void operator=(const BigInt &rhs){
    len=rhs.len;
    for(int i=0;i<len;i++)
      digit[i]=rhs.digit[i];
  }
  BigInt operator*(int scale)const{
    long carry=0;
    BigInt out=*this;
    for(int i=0;i<len;i++)
      out.digit[i]=(digit[i]<<1)+carry,
      carry=out.digit[i]/base,
      out.digit[i]%=base;
    if(carry) out.digit[out.len++]=carry;
    return out;
  }
  void PrintNum(){
    printf("%ld",digit[len-1]);
    for(int i=len-2;i>=0;i--)
      printf("%017ld",digit[i]);
    putchar('\n');
  }
}twoPowers[1001];
int main(){
  //
  twoPowers[1]=BigInt(1);
  for(int i=2;i<=1000;i++)
    twoPowers[i]=twoPowers[i-1]*2,
    twoPowers[i].digit[0]++; // <- 這個是偷懶的作法，幾乎不會發生溢位的情況
  //
  for(int N;scanf("%d",&N)!=EOF;)
    twoPowers[N].PrintNum();
}
