/* 狀態轉移：
 * 只有當Ｎ顆骰子可以組合出來的點數透過新增一顆骰子的點數(１-６)才能
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxK=1e3;
const int MaxN=20;
long cnt[MaxN+1][MaxN*6+1]={};

int main(){
	cnt[0][0]=1;
	for(int DiceCnt=1;DiceCnt<=MaxN;DiceCnt++)
		for(int Point=DiceCnt-1;Point<=6*DiceCnt;Point++)
			for(int addv=1;addv<=6;addv++)
				cnt[DiceCnt][Point+addv]+=cnt[DiceCnt-1][Point];
	int CaseT, DiceCnt, Point;
	scanf("%d\n",&CaseT);
	while(CaseT--)
		scanf("%d %d\n",&DiceCnt,&Point),
		printf("%ld\n",cnt[DiceCnt][Point]);
}