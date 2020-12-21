/* 給定Ｎ元和７種貨幣面值，在最少的貨幣個數的前提下輸出兌換方式
 * 因為題目的幣值間呈倍數關係，可以採用貪婪法計算最少個數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e4;
const int coin[7]={1000,500,100,50,10,5,1};
int cnt[7];
int main(){
	for(int N; scanf("%d\n",&N)!=EOF;){
		printf("%d",N);
		for(int i=0;i<=6;i++)
			cnt[i]=N/coin[i], N%=coin[i];
		bool First=1;
		for(int i=0;i<=6;i++)
			if(cnt[i]>0){
				if(First)
					First=0, 
					printf(" = %d*%d",coin[i],cnt[i]);
				else	
					printf(" + %d*%d",coin[i],cnt[i]);
			}
		putchar('\n');
	}
}
