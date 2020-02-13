/* 給定一個數字，最大化n-p*x 的質數p 且滿足 p*x ≤ n < p*(x+1)
 * 最大化n-p*x＝最小化 x=1 ＝找到一個質數p大於Ｎ的一半。
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97}; // 100以內的25個質數
int main(){
	// 建質數表
	vector<bool> NotPrime(MaxN+1);
	for(int p:prime)
		for(int j=3;p*j<=MaxN;j+=2)
			NotPrime[p*j]=1;
	for(int i=101;i<=MaxN;i+=2)
		if(NotPrime[i]==0)
			prime.push_back(i);

	int caseT, N, tag;
	scanf("%d\n",&caseT);
	while(caseT--)
		scanf("%d\n",&N),
		printf("%d\n",*upper_bound(prime.begin(),prime.end(),N>>1));
}