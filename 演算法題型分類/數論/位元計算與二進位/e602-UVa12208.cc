/* 題目要求計算區間內所有數字二進位化後１的個數
 * (X)直覺：把Ａ-Ｂ每個數字二進位化後計算１的個數後累加起來
 * (v)二進位的規律觀察：從０-２^n-1 １的個數剛好是２^n*n/2
 *    將問題拆解為CountOne(B)-CountOne(A-1)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxNumber=2e9; // 0 ≦Ａ≦Ｂ≦ 2e9
inline long CountOnes(int num){
	if(num<=0) return 0;
	// 轉換為二進位，並記錄每個位元
	vector<int> BitNum; 
	for(;num>0;num>>=1)
		BitNum.push_back(num&1);
	//
	long out=0, one_cnt=0;
	for(long i=BitNum.size()-1;i>=0;i--){
		if(BitNum[i]){
			out+=one_cnt*(1<<i)+(i*((1<<i)>>1));
			one_cnt++;
		}
	}
	return out+one_cnt;
}
int main(){
	int A,B;
	for(int caseI=1;scanf("%d %d\n",&A,&B) and A or B;caseI++)
		printf("Case %d: %ld\n",caseI,CountOnes(B)-CountOnes(A-1));
}