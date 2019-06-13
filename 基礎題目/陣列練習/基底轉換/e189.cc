// 利用Ｎ進位的基底轉換判斷是否可以被(Ｎ+1)整除
// 各自對奇偶位做總和後算差值是否為(Ｎ+1)的倍數，遞迴處理直到Ｎ<3

#include<bits/stdc++.h>
using namespace std;

inline bool IsThree(int x,int sumn=0){
  if(x<=2) return x==0;
  for(bool add=true; x; x>>=1, add^=true)
    (add)? sumn+=x&1: sumn-=x&1;
  return IsThree(sumn);
}
int main(){
  int N;
  while(scanf("%d",&N)!=EOF)
    puts((IsThree(N))?"YES":"NO");
}