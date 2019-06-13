// 不一定要用遞迴解，找規律也可以
// 規律:(左上/右上/左下/右下)的關係對應(00,10,01,11)=>(00,11,10,01)
#include<iostream>
using namespace std;

bool scanInt(int &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  int R, C;
  scanInt(R), R--;
  scanInt(C), C--;
  long ans=1;
  int maxL=max(__lg(R),__lg(C))+1;
  for(long base=1; maxL--; base<<=2,R>>=1,C>>=1)
    ans+=(( 4-((C&1)<<1)-(R&1) )%4)*base;
  printf("%lu\n",ans);
}