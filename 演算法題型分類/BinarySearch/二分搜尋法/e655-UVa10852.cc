/* 給定一個數字，最大化ｎ-ｐ*ｘ 的質數ｐ 且滿足 ｐ*ｘ ≤ n < ｐ*(ｘ+1)
 * 解題關鍵：何謂題目定義的最大化？推導出存在一個質數ｐ大於Ｎ的一半
 * max{ ｎ-ｐ*ｘ }＝min{ x }＝ x=1，找到一個質數p大於Ｎ的一半。
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
/* 題目給的Ｓ最大是1e4，代表只需要確認100以內的25個質數 */
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
	/* seive */
	vector<bool> NotPrime(MaxN+1);
	for(int p:prime)
		for(int j=3;p*j<=MaxN;j+=2)
			NotPrime[p*j]=1;
	for(int i=101;i<=MaxN;i+=2)
		if(NotPrime[i]==0)
			prime.push_back(i);
	/* main */
	int caseT, N, tag;
	scanf("%d\n",&caseT);
	while(caseT--)
		scanf("%d\n",&N),
		printf("%d\n",*upper_bound(prime.begin(),prime.end(),N>>1));
}