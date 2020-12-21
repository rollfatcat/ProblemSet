// 題目要求等同 c412
#include<bits/stdc++.h>
using namespace std;

int main(){
  int Qs=0, As=0;
  long cnt=0;
  for(char buffer; (buffer=getchar())!=EOF; )
    if(buffer=='Q')   cnt+=As, Qs++;
    else if(buffer=='A')  As+=Qs;
  printf("%ld\n",cnt);
}