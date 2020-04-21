/* 卡塔蘭數列( Catalan Number )
 * 觀察規律可以發現狀態轉移： ƒ(Ｎ)＝Σƒ(i)×ƒ(Ｎ-1-i)，０≦ｉ<Ｎ
 * Ｎ≦ 100，需要做大數運算
 * Ｎ= 68,   86218923998960285726185640663701108500
 * Ｎ= 69,  337485502510215975556783793455058624700
 * Ｎ= 70, 1321422108420282270489942177190229544600
 * Ｎ=100, 896519947090131496687170070074100632420837521538745909320
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
const long base=1e9;
vector<long> BIGNUM[MaxN+1];
void BIGNUM_MUL(vector<long> &ths,vector<long> &rhs,vector<long> &out,long carry=0){
	int outL=ths.size()+rhs.size();
	for(int i=out.size();i<outL;i++)
		out.push_back(0);
	for(int i=0;i<ths.size();i++)
		for(int j=0;j<rhs.size();j++)
			out[i+j]+=ths[i]*rhs[j];
	for(int i=0;i<out.size();i++)
		out[i]+=carry, 
		carry=out[i]/base, 
		out[i]%=base;
	if(carry>0)         
		out.push_back(carry);
	if(out.back()==0) 
		out.pop_back();
}

int main(){
	
	BIGNUM[0].push_back(1);
	BIGNUM[1].push_back(1);
	BIGNUM[2].push_back(2);
	BIGNUM[3].push_back(5);
	// 
	for(int idx=4;idx<=MaxN;idx++)
		for(int i=0;i<idx;i++)
			BIGNUM_MUL(BIGNUM[i],BIGNUM[idx-1-i],BIGNUM[idx]);
	
	for(int N;scanf("%d",&N)!=EOF;){
		printf("%ld",BIGNUM[N].back());
		for(int i=BIGNUM[N].size()-2;i>=0;i--)
			printf("%09ld",BIGNUM[N][i]);
		putchar('\n');
	}
	
}
