/* 根據輸入的Ｎ計算從1開始的連續階乘
 * 直覺：枚舉1-Ｎ各自做質因數分解
 * (1) 基於上述做法＋建表
 * (2) 反算Ｎ以內的質數，對每個質數都計算次方項的個數
 *     Σi [Ｎ/p^i]
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4; //
bool NotP[MaxN];
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
	// 建質數表：1e4內的質數
	for(int i=4;i<MaxN;i+=2) NotP[i]=1;
	for(int i=1;i<prime.size();i++)
		for(int j=3;prime[i]*j<MaxN;j+=2)
			NotP[prime[i]*j]=1;
	for(int i=101;i<MaxN;i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	prime.push_back(MaxN+1);
 
	for(int N;scanf("%d",&N)!=EOF;){
		printf("%d! =",N);
		for(int p,i=0;prime[i]<=N;i++){
			p=0;
			for(int B=prime[i];B<=N;B*=prime[i])
				p+=N/B;
			if(i>0) printf(" *");
			printf(" %d^%d",prime[i],p);
		}
		putchar('\n');
	}
}