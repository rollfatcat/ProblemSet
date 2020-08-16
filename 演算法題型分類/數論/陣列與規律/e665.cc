/* 給定Ｎ層串珠，輸出ＲＧＢ三種顏色各自需要的個數？
 * 每層串珠由左而右必須依照ＲＧＢ的順序串上，而第ｉ層時的總長度為２的ｉ-1次方。
 * 解題關鍵：３個顏色一循環，
 * 長度餘數是１代表Ｒ比ＧＢ多一顆，長度餘數是２代表ＲＧ比Ｂ多一顆。
 * 長度本身的餘數也是１２１２的循環，可以推斷
 *  (1) Ｂ一定是最少
 *  (2) Ｇ比Ｂ多出Ｎ÷２顆
 *  (3) Ｒ比Ｂ多出Ｎ顆
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=30;
int base[MaxN+1]={};
int main(){
	for(int i=0;i<MaxN;i++)
		base[i+1]=(1<<i)/3+base[i];
	
	int N;
	while(scanf("%d\n",&N)!=EOF)
		printf("%d %d %d\n",base[N]+N,base[N]+(N>>1),base[N]);
}