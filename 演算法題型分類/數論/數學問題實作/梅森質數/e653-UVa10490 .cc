/* 需要知道『完美數』的定義和性質
 * 定義：該數字的因數和＝該數字
 * 性質：一個偶數是完美數，若且唯若它具有如下形式：2^n-1是質數(梅森質數)，充分性由歐幾里得證明，而必要性則由歐拉所證明。
 * 所以題目的要求轉為：給定Ｋ，問2^Ｋ-1是不是質數？
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxK=32; // 1 <ｋ≤ 31
const int MaxN=(1<<31)-1;
vector<bool> NotP(sqrt(MaxN)+1);
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31};
int main(){
	for(int i=3;i<=sqrt(sqrt(MaxN));i+=2)
		if(NotP[i]==0)
			for(int j=(i<<1)+i;j<=sqrt(MaxN);j+=(i<<1))
				NotP[j]=1;
	for(int i=33;i<=sqrt(MaxN);i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	//
	for(int K,N;scanf("%d\n",&K) and K;){
		N=(1<<K)-1;
		//
		bool IsP=1;
		for(int i=0;i<prime.size() and prime[i]*prime[i]<=N and IsP;i++)
			IsP= (N%prime[i]);
		if(IsP) printf("Perfect: %ld!\n",((long)1<<K-1)*N);
		else if(binary_search(prime.begin(),prime.end(),K)) printf("Given number is prime. But, NO perfect number is available.\n");
		else printf("Given number is NOT prime! NO perfect number is available.\n");
	}
}