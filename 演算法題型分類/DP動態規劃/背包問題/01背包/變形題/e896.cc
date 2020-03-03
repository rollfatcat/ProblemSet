/* 題目敘述和 e895 一樣是給定長度Ｎ的長廊需要放滿貨品，問 #方法數？
 * 但多了一個規定：(左側的)貨品長度一定要比後面的(右側的)短。
 * 規定(左側的)貨品長度一定要比後面的(右側的)短＝不存在兩個長度相同的貨品＝01背包
 * 依照貨品的最大長度由短開始往長的更新，確保狀態轉移時長度最長者一定是放在最後面。
 * 所有狀態：所有長度的長廊(0≦Ｎ≦500)
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxL=501; // Ｌ≦500
long cnt[MaxL]={1};
int main() {
	for(int nowL=1;nowL<MaxL;nowL++)
		for(int i=MaxL-1;i>=nowL;i--)
			cnt[i]+=cnt[i-nowL];
	for(int N;scanf("%d\n",&N)!=EOF;)
		printf("%ld\n",cnt[N]);
	
}