/* 給定Ｎ位同學(號碼介於０~Ｎ-1)和Ｋ段關係，輸出班級上小團體的數量？
 * 關係：只要屬於同一段關係即為同一個小團體，{Ａ,Ｂ}+{Ｃ,Ｄ}+{Ａ,Ｃ}＝{Ａ,Ｂ,Ｃ,Ｄ}
 * 解題關鍵：Disjoint Set
 */
#include<bits/stdc++.h>
using namespace std;
 
vector<int> sym;
vector<int> cnt;
inline int Symbal(int x){
	if(sym[x]!=x) sym[x]=Symbal(sym[x]);
	return sym[x];
}
int main(){
	int N, K, A, B;
	while(scanf("%d %d\n",&N,&K)!=EOF){
		sym.resize(N);
		cnt.resize(N,1);
		for(int i=0;i<N;i++)
			sym[i]=i;
		int rem=N;
		while(K-->0){
			scanf("%d %d\n",&A,&B);
			int Sa=Symbal(A);
			int Sb=Symbal(B);
			if(Sa==Sb) continue;
			rem--;
			if(cnt[Sa]>=cnt[Sb]){ 
				sym[Sb]=Sa;
				cnt[Sa]+=cnt[Sb];
			}else{
				sym[Sa]=Sb;
				cnt[Sb]+=cnt[Sa];
			}
		}
		printf("%d\n",rem);
	}
}