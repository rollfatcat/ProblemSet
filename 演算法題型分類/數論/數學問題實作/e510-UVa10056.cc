/* 等比級數的和：
 * 給定Ｎ個人、觸發成功事件的機率Ｐ和第Ｄ位玩家，問Ｄth玩家贏得遊戲的機率？
 * 前Ｄ-1位玩家都沒贏且Ｄth玩家贏Game(考慮到遊戲的回合是無限制(只要沒玩家贏就繼續))
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e3;
const int MaxN=1e3;
int main(){
	int caseT, N, D;
	double P;

	scanf("%d\n",&caseT);
	while(caseT--)
		scanf("%d %lf %d\n",&N,&P,&D),
		printf("%.4lf\n",P*pow(1-P,D-1)/(1-pow(1-P,N)));
}