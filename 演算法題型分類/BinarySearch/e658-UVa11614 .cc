/* 給定Ｎ，求最大化ｘ滿足Ｎ ≧ x(x+1)/2
 * Ｎ＝1e18 時，無法事先建表用二分搜尋法找到上述的 x
 * 只能用開根號的方式取得一個近似值後做調整
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxN=1e18;
int main() {
	int caseT;
	scanf("%d",&caseT);
	
	long N, tag;
	while(caseT--){
		scanf("%ld",&N);
		N<<=1, tag=sqrt(N);
		printf("%ld\n",tag-(tag*(tag+1)>N));
	}
}