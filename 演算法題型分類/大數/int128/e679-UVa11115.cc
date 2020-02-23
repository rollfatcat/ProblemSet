/* 把Ｄ個光碟分給Ｎ個人，問 #組合。
 * 光碟和人都視為不同，所以 #組合＝Ｎ^Ｄ
 * 數值最大＝10^25，代表可以用 __int128 計算，但需要自己寫輸出
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=10; // 1 ≤ Ｎ ≤ 10
const int MaxD=25; // 0 ≤ Ｄ ≤ 25
int main(){
	for(int L,N,D;scanf("%d %d\n",&N,&D);){
		if(N==0 and D==0) break;
		__int128 ret=1;
		for(int i=0;i<D;i++)
			ret*=N;
		char retss[40];
		for(L=0;ret>0;L++,ret/=10)
			retss[L]=ret%10+'0';
		while(L)
			putchar(retss[--L]);
		putchar('\n');	
	}
}