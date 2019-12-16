/* 對於任何整數集合，都有一個整數Ｄ，這樣每個給定的整數除以d都會留下相同的餘數, 最大化Ｄ。
 * 利用『差值』消除餘數後取最大公因數, 注意數字有負數導致求出的最大公因數為負。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000;
int num[MaxN];

int main(){
	int cnt, ans;
	while(scanf("%d",&num[0]) and num[0]){
		for(cnt=1;scanf("%d",&num[cnt]) and num[cnt];cnt++);
		sort(num,num+cnt);
		ans=num[1]-num[0];
		for(int i=2;i<cnt;i++)
			ans=__gcd(ans,num[i]-num[i-1]);
		printf("%d\n",ans);
	}
}