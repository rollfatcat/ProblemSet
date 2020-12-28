/* 本質是數學問題，須知道排列組合的計算方式
 * 以範例測資 bdac 11 為例：可以看到 11＞6 ＝ 3! ，因此前面已經先排完一輪長度為３的字典序(即順序第二～順序第四的符號之排列)。
 * 所以，可以推導出 b 為該字典第二順位的符號。順便將 11 減去６，以便等等做判斷。
 * 接著對於剩下的三個符號 dac 其序位為 5，而 5＞4 ＝ 2 × 2! ，
 * 代表剩下的三個符號中已經排到要以剩下的符號中第三順位(即原本的第四順位)為開頭。因此推導出 d 為第四順位。並將 5 減去 4 。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=5e3;
const int MaxN=20; // 題目保證給定的字元皆不同
long fac[MaxN+1]={1};
char org[MaxN+2];
char ans[MaxN+2];
int main(){
	// 建表：階乘表，20！≦ 3e18
	for(int i=1;i<=20;i++)
		fac[i]=i*fac[i-1];
	
	int caseT, sft, L;
	scanf("%d",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%s %d",org,&sft);
		L=strlen(org); sft--; ans[L-1]='\0';
		vector<int> pos;
		for(int i=0;i<L;i++)
			pos.push_back(i);
		for(int i=1;i<L;i++){
			int tag=sft/fac[L-i]; sft%=fac[L-i];
			ans[pos[tag]]=org[i-1];
			pos.erase(pos.begin()+tag);
		}
		ans[pos[0]]=org[L-1];
		printf("Case %d: %s\n",caseI,ans);
	}
}