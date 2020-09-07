/* 給定一個數字, 若該數字是質數則輸出0, 合數則輸出鄰近的兩個質數差
 * 解題關繫：seive＋二分搜尋法的STL
 * 篩法建表後做二分搜尋法。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxPrime=1299709; // 100000th prime
int main(){
	// 篩法：建質數表
	vector<bool> NotP(MaxPrime);
	for(int i=3;i<sqrt(MaxPrime);i++)
		if(NotP[i]==0)
			for(int j=3*i;j<MaxPrime;j+=(i<<1))
				NotP[j]=1;
	vector<int> prime;
	prime.push_back(2);
	for(int i=3;i<MaxPrime;i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	prime.push_back(MaxPrime);
	
	int K; // 1 < k ≦ 1299709
	while(scanf("%d",&K) and K){
		int tag=lower_bound(prime.begin(),prime.end(),K)-prime.begin();
		printf("%d\n",(prime[tag]==K)? 0: prime[tag]-prime[tag-1]);
	}
	
}