/* 經典 Joseph 問題：動態規劃推導
 * 給定Ｎ代表Ｎ個人，每隔Ｍ個人後殺掉且規定第一個殺的一定是第一個人，問Ｍ最小時才能讓第二個人活到最後
 * 原先動態規劃的方法第一個消去的是Ｍ-1th 但這題規定要０th，所以需要『重新編號』(shift)
 * 而題目規定活到最後的第二個人新編號＝Ｍth，考慮到Ｍ>Ｎ時則為Ｍ%Ｎth
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=150; // 3 ≤ Ｎ < 150
int MinM[MaxN]={};
int main(){
	for(int N,tryM;scanf("%d\n",&N) and N;){
		if(MinM[N]==0){
			for(tryM=2;true;tryM++){
				int now=0;
				for(int turn=2;turn<=N;turn++)
					now=(now+tryM)%turn;
				if(now==tryM%N) break;
			}
			MinM[N]=tryM;
		}
		printf("%d\n",MinM[N]);
	}
}