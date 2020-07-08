/* 給Ｑ個數字，每給定Ｎ後帶入下述的函數Ｈ(n)，輸出回傳的答案？
 * 直接觀察可以發現Ｎ=2e9時會導致TLE，因此必須觀察規律"除法商數的頻率"
 * 以 Ｎ=24 為例：
 *    24÷2＝12 ... 12除了代表÷２的商數，也代表 13-24 的商數都是１
 *    24÷3＝ 8 ...  8除了代表÷３的商數，也代表  9-12 的商數都是２
 *    24÷4＝ 6 ...  6除了代表÷４的商數，也代表  7- 8 的商數都是３
 *    24÷5＝ 4 ...  4除了代表÷５的商數，也代表  5- 6 的商數都是４，注意這時÷5的商數不可重複計算
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=(1<<31)-1;
const int MaxQ=1e3;
long H(int n,long res=0){
    for(int i=1;i<=n;i++)
        res+= n/i;
    return res;
}

inline long Func(int N,long res=0){
	long Dnd=N, Dsr=1;
	for(int now=2; Dsr<Dnd; now++){
		res+= (Dnd-(N/now))*Dsr;
		Dnd=N/now, Dsr++;
		if(Dsr<=Dnd) res+=Dnd;
	}
	return res+N;
}
int main(){
	int Q, N;
	scanf("%d\n",&Q);
	while(Q--)
		scanf("%d\n",&N),
		printf("%ld\n",Func(N));
}
