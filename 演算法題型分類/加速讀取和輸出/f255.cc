/* 給定密碼長度Ｎ，密碼每個位元只會由０或１構成，輸出長度Ｎ所有密碼組合的數量？
 * 解題關鍵：大數(加速進位版本)＋加速輸出(putchar_unlocked())
 * Ｎ最大是1e4，所以２的1e4次方會是大數且長度極長，故需要加速輸出。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const long mod=1e18;
vector<long> two[MaxN+1];

inline bool scanInt(int &x){ char c;for(x=0;'0'<=(c=getchar_unlocked()) and c<='9'; x=(x<<3)+(x<<1)+c-'0'); return x>0;}
inline void prLong(long x,bool zero,int L=0){
	char ss[20];
	for(;x>0;ss[L++]='0'+x%10,x/=10);
	if(zero)	 for(int i=L;i<18;i++,putchar_unlocked('0'));
	for(L--;L>=0;putchar_unlocked(ss[L--]));
}
int main(){
	two[0].push_back(1);
	for(int i=1;i<=MaxN;i++){
		long carry=0;
		for(long v:two[i-1]){
			carry+= v<<1;
			two[i].push_back(carry%mod);
			carry/=mod;
		}
		if(carry>0)
			two[i].push_back(carry);
	}
	
	int N;
	while(scanInt(N)){
		prLong(two[N].back(),0);
		for(int i=two[N].size()-2;i>=0;i--)
			prLong(two[N][i],1);
		putchar('\n');
	}
}
