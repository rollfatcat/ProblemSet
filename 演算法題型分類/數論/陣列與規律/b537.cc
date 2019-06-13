/* 號碼出現的位置：
          1
    3           2
 5     7     6     4
9 13 15 11 10 14 12 8
   遞迴關係：
   ƒ(n)=1, n=1
   ƒ(n)=ƒ(n-1)x2, n>1
   ƒ(n)=ƒ(1/n)+1, n<1
*/
#include<bits/stdc++.h>
using namespace std;

struct FRAC{
  int num, den, GCD;
  void reduce(void){ GCD=__gcd(num,den); num/=GCD, den/=GCD; }
}now;
int main(){
  while(scanf("%d %d",&now.num,&now.den)==2){
    int v[70]={}, idx=0;
		while(now.num!=now.den){
			if(now.num>now.den)
				v[idx++]=0,
				now.num-=now.den;
			else
				v[idx++]=1,
				swap(now.num,now.den);
			now.reduce();
			printf("%d %d %d\n",v[idx-1],now.num,now.den);
		}
		long ret=1;
		while(--idx>=0)
			(v[idx])?ret++:ret<<=1;
		printf("%ld\n", ret);
  }
}