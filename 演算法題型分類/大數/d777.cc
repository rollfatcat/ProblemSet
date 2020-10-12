/* 給定Ｐ，輸出 power(２,Ｐ)-1 的長度和尾端５００位數(不足補０)
 * 解題關鍵：快速幂( 難度題，考慮後可以解出 )
 * 解題盲點：題目要輸出「長度」且尾端的位數，會誤以為需要快速幂＋調整基底(降低進位次數)實現大數乘法。
 *         但題目敘述已經提及：Ｐ=3021377，有 909526 位數，所以為了計算長度不可能做大數乘法。
 *         實際上長度只要利用log計算就能推測出「位數長度」＝ ceil( Ｐ×log10(2) )
 *         尾端的 500 位數意味著大數乘法只需要 500 格的陣列做紀錄即可(太長的可以捨去)。 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxP=3100000;
const long base=1e5;
vector<long> pwr[32];
vector<long> val[2];

void BigNum_Mul(vector<long> &a,vector<long> &b,vector<long> &c){
	fill(c.begin(),c.end(),0);
	int maxsz=min(a.size()+b.size(),(unsigned long)100);
	c.resize(maxsz);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size() and i+j<maxsz;j++)
			c[i+j]+=a[i]*b[j];
	long carry=0;
	for(int i=0;i<maxsz;i++)
		c[i]+=carry, carry=c[i]/base,
		c[i]%=base;
	if(c.back()==0)
		c.pop_back();
}
int main(){
	int P, BitMask=2; 
	bool now=1, pre=0;
	scanf("%d\n",&P);
	
	printf("%d\n",(int)(P*log10(2)+1));
	
	pwr[0].push_back(2);
	val[0].push_back( (P&1)? 2:1 );
	for(int p=1; p<=__lg(P); p++,BitMask<<=1){
		BigNum_Mul(pwr[p-1],pwr[p-1],pwr[p]);
		if( P&BitMask ){
			BigNum_Mul(pwr[p],val[pre],val[now]);
			swap(now,pre);
		}
	}
	
	val[pre].resize(100);
	for(int i=99;i>0;i--){
		printf("%05ld",val[pre][i]);
		if(i%10==0)
			putchar('\n');
	}
	printf("%ld\n",val[pre][0]-1);
}