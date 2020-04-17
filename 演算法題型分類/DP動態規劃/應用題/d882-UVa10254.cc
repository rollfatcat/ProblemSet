/* 題目中已經提到動態規劃的『狀態轉移』方式
 * ƒ(Ｎ)＝min( 2*ƒ(Ｎ-Ｋ)＋2^Ｋ-1 )，０≦Ｋ≦Ｎ
 * 但Ｎ≦１e4時暴力法枚舉Ｋ取最小值(做大數比較)時會TLE
 * 再觀察Ｋ的規律可以發現：0,1,1,2,2,2,3,3,3,3,...
 * ƒ(Ｎ)＝2*ƒ(Ｎ-Ｋ)＋2^Ｋ-1 ，Ｋ(Ｋ-1) ≦ 2Ｎ<Ｋ(Ｋ+1), (K-1)就是我們需要的數值。
 * 加速：base=1e18
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const long base=1e18;
vector<long> dpv[MaxN+1];
vector<long> TwoPower[MaxN+1];
int main(){

	dpv[0].push_back(0);
	dpv[1].push_back(1);
	dpv[2].push_back(3);	
	TwoPower[1].push_back(2); 
	for(int idx=3,k=2;idx<=MaxN;k++){
		long carry=0;
		for(long x:TwoPower[k-1])
			TwoPower[k].push_back((x<<1)+carry),
			carry=TwoPower[k].back()/base,
			TwoPower[k].back()%=base;
		if(carry) TwoPower[k].push_back(carry);
		for(int a=0;a<=k and idx<=MaxN;a++,idx++){
			carry=0;
			for(long x:dpv[idx-k])
				dpv[idx].push_back((x<<1)+carry),
				carry=dpv[idx].back()/base,
				dpv[idx].back()%=base;
			if(carry) dpv[idx].push_back(carry);
			carry=-1;
			for(int i=0;i<TwoPower[k].size();i++)
				dpv[idx][i]+=carry+TwoPower[k][i],
				carry=dpv[idx][i]/base,
				dpv[idx][i]%=base;
			for(int i=TwoPower[k].size();carry>0 and i<dpv[idx].size();i++)
				dpv[idx][i]+=carry,
				carry=dpv[idx][i]/base,
				dpv[idx][i]%=base;
			if(carry) dpv[idx].push_back(carry);
		}
	}
	for(int N;scanf("%d\n",&N)!=EOF;){
		printf("%ld",dpv[N].back());
		for(int i=dpv[N].size()-2;i>=0;i--)
			printf("%018ld",dpv[N][i]);
		putchar('\n');
	}
}