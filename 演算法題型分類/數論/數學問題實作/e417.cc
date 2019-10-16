/* 多項式分配律 */
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int N, x;
	long sum_pow1, sum_pow2;
	while(scanf("%d",&N)==1){
		sum_pow1=sum_pow2=0;
		while(N--)
			scanf("%d",&x),
			sum_pow1+=x,
			sum_pow2+=x*x;
		printf("%ld\n",(sum_pow1*sum_pow1-sum_pow2)>>1);
	}
}