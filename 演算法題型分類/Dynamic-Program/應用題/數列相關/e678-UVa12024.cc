/* 錯排問題：1-Ｎ位置的人不能拿對應自己位置號碼的所有方法數。
 * 標準動態規劃題目：等同 d443，
 * 狀態轉移：DP[N]=(N-1)x(DP[N-1]+DP[N-2])
 * Ｎth 位置和  (1,Ｎ-1)位置任選其一彼此交換號碼，則方法數＝DP[N-2]
 * Ｎth 位置選走(1,Ｎ-1)的號碼且 被拿走號碼的位置獲得號碼Ｎth，
 *      但基於『上述情況』互斥該位置不能持有號碼Ｎth，則方法數＝DP[N-1]
 * 題目給的Ｎ≤ 12，12！需用 long 儲存數值。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=13; // 12！=479001600
long fac[MaxN];
long cnt[MaxN];
int main(){
	fac[1]=1, fac[2]=2;
	cnt[1]=0, cnt[2]=1;
	for(int i=3;i<MaxN;i++)
		fac[i]=fac[i-1]*i,
		cnt[i]=(i-1)*(cnt[i-1]+cnt[i-2]);
	int caseT, N;
	scanf("%d\n",&caseT);
	while(caseT--)
		scanf("%d\n",&N),
		printf("%ld/%ld\n",cnt[N],fac[N]);
}