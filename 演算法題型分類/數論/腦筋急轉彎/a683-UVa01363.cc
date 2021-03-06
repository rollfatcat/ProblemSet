/* 給定一組Ｎ,Ｋ後帶入下述的函數Ｈ(Ｎ,Ｋ)，輸出回傳的答案？
 * 直接觀察可以發現Ｎ=1e9 時會導致TLE，因此必須觀察規律"除法商數的頻率"
 * 類似前置題：d193-UVa11526
 * 觀察 Ｎ＞K 時取模的運算＝無效，故 Ｎ＞K 的區段和＝Ｋ×(Ｎ-Ｋ)
 *     Ｎ＜K 時分段處理，枚舉除數是２-sqrt(Ｎ) 的並累加區段和(需討論當Ｎ剛好落在區間時的首項)
 * 37÷ 1＝37 ... 0 >> 37÷37＝ 1 ... 0
 *                    37÷19＝ 1 ...18  >> 等差級數且公差＝1
 * 37÷ 2＝18 ... 1 >> 37÷18＝ 2 ... 1
 *					  37÷13＝ 2 ...11  >> 等差級數且公差＝2，首項＝前一個餘數
 * 37÷ 3＝12 ... 1 >> 37÷12＝ 3 ... 1
 *					  37÷10＝ 3 ... 7  >> 等差級數且公差＝3
 * 37÷ 4＝ 9 ... 1 >> 37÷ 9＝ 4 ... 1
 *                    37÷ 8＝ 4 ... 5  >> 等差級數且公差＝4
 * 37÷ 5＝ 7 ... 2 >> 37÷ 7＝ 5 ... 2
 * 37÷ 6＝ 6 ... 1 >> 37÷ 6＝ 6 ... 1  >> 等差級數且公差＝5
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e9;
const int MaxK=1e9;
long H(long N,long K,long r=0){
	for(int i=2;i<=N;i++)
		r+=K%i;
	return r;
}
long Func(long N,long K){
	long rem=(N>K)? (N-K)*K: 0;
	int Dsr, nowQ, preQ=K;
	long cnt;
	for(Dsr=2; Dsr<=N and Dsr*Dsr<=K; Dsr++){
		nowQ=K/Dsr;
		rem+=K%Dsr; 
		if(nowQ<N and N<=preQ)
			preQ=N;
		cnt=preQ-nowQ;
		if(N>nowQ)	
			rem+= (K%preQ)*cnt+(cnt*(cnt-1)>>1)*(Dsr-1);
		preQ=nowQ;
	}
	return (preQ==Dsr)? rem+K%Dsr: rem;
}
int main(){
	for(int N, K;scanf("%d %d\n",&N,&K)!=EOF;)
		printf("%ld\n",Func(N,K));
}