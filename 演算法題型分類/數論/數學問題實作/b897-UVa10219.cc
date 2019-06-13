// 數論：位數長度對10取㏒做指數運算
// 相乘=次方項相加，記得取floor(x)+1 而不是ceil(x)
#include<iostream>
#include<cmath>
using namespace std;

bool scanLong(long &x){char c;for(x=0;(c=getchar())>='0' and c<='9';x=(x<<3)+(x<<1)+c-'0');return c!=EOF;}
int main(){
  for(long n,k; scanLong(n) and scanLong(k);){
    k=min(n-k, k);
    double sum=0.0;
    for(long i=n-k+1;i<=n;i++)
      sum+=log10(i);
    for(long i=2;i<=k;i++)
      sum-=log10(i);
    n=floor(sum)+1;
    printf("%lu\n",n);
  }
}