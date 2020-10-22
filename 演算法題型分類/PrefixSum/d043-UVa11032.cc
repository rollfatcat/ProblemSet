/* 根據給予的參數個數，依照函數輸出對應的答案？
 * 條件： x＋SomOfDigits(x)，Ex : 99+SOD(99)=99+9+9=117
 * 輸入１個參數：回傳最小符合條件( 自己＋每個位數總和＝輸入參數 )的數字？
 * 輸入２個參數：回傳區間內有多少個不存在計算條件的數字個數？
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e3;
const int MaxN=1e7+1;
int frm[MaxN]={};
int prS[MaxN]={1};
int main(){
	for(int now_v=1; now_v<MaxN; now_v++){
		int add=0;
		for(int i=now_v; i>0; i/=10)
			add+=i%10;
		if(now_v+add<MaxN){
			if(prS[now_v+add]==0)
				frm[now_v+add]=now_v;
			prS[now_v+add]=1;
		}
		prS[now_v]=prS[now_v-1]+(frm[now_v]==0);
	}
	int caseT, A, B;
	scanf("%d\n",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d",&A);
		if(getchar()==' '){
			scanf("%d\n",&B);
			printf("Case %d: %d\n",caseI,prS[B]-prS[A-1]);
		}else
			printf("Case %d: %d\n",caseI,(frm[A]==0)? -1: frm[A]);
 
	}
}
