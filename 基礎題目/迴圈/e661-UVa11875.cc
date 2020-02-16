/* 給定Ｎ個嚴格遞增/遞減的正整數，輸出中位數
 * 因為數列『已經排序』且題目保證Ｎ是奇數，所以中位數＝陣列中間位置的數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;// T＜100
const int MaxN=10;     // 1＜N＜11 and N is odd
int main(){
	int caseT, N, x, stop;
	scanf("%d",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d",&N); 
		stop=N>>1;
		for(int i=0;i<stop;i++)
			scanf("%d",&x);
		scanf("%d",&x); printf("Case %d: %d\n",caseI,x);
		for(int i=stop+1;i<N;i++)
			scanf("%d",&x);
	}
}