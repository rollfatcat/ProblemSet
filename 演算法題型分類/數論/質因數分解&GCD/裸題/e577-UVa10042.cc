/* 輸出比Ｎ大的 Smith Number, Ｎ<1e9
 * Smith Number：非質數 且 位數和＝質因數分解後的質數和
 * 為了判斷質數做篩法, 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e9;
const int MaxsN=sqrt(MaxN);
vector<bool> NotP(MaxsN);
vector<int> prime={2};
inline int SumDigit(int x,int out=0){
	for(;x>0;x/=10)
		out+=x%10;
	return out;
}

int main(){
	// 建質數表
	for(int i=4;i<MaxsN;i+=2)
		NotP[i]=1;
	for(int i=3;i<=sqrt(MaxsN);i+=2)
		if(NotP[i]==0)
			for(int j=3;i*j<MaxsN;j+=2)
				NotP[i*j]=1;
	for(int i=3;i<MaxsN;i+=2)
		if(NotP[i]==0)
			prime.push_back(i);
	//
	int caseT, N;
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%d",&N);
		for(N++; 1;N++){
			bool IsPrime=1;
			int sum_fac=0, num=N, p;
			for(int i=0; i<prime.size() and num>=prime[i]*prime[i]; i++){
				for(p=0; num>0 and num%prime[i]==0; num/=prime[i],p++);
				sum_fac+=p*SumDigit(prime[i]);
				IsPrime&= p==0;
			}
			if(num>1) sum_fac+=SumDigit(num);
			if(IsPrime==0 and sum_fac==SumDigit(N)){
				printf("%d\n",N);
				break;
			}
		}
	}
}