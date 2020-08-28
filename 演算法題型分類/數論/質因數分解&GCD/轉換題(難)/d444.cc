/* 給定Ｎ個數字和Ｍ(最多１５個)個除數，輸出１到Ｎ的範圍內不會被所有除數整除的數字個數？
 * 解題關鍵：排容原理( 歐拉函數 )
 * 舉例：除數為２、３、５時，需要扣除(２)(３)(５)的倍數，
 * 但(２,３)(２,５)(３,５)最小公倍數的倍數因為被重複扣除需要加回，
 * 且(２,３,５)最小公倍數的倍數又因為被重複加回要在扣除
 * ... 選取個數是奇數要扣除，偶數時要加回。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=INT_MAX;
const int MaxM=15;
long ans;
int N, M;
int num[MaxM];
long GCD(long a,long b){ return (a%b==0)? b:GCD(b,a%b); }
void Pick(int st,long LCM,bool add){
	/* Branch Cut：當目前的最小公倍數已經超過Ｎ時就能停止 */
    if(LCM>N) return;
    /* 根據選取的個數決定是 扣除 還是 加回？ */
	ans=(add)? ans+N/LCM: ans-N/LCM;
	for(int now=st;now<M;now++)
		Pick(now+1, LCM*num[now]/GCD(LCM,num[now]),!add);
}
int main(){
	while(scanf("%d %d\n",&N,&M) and N>0){
		for(int i=0;i<M;i++)
			scanf("%d",&num[i]);
		ans=N;
		for(int i=0;i<M;i++)
			Pick(i+1,num[i],0);
		printf("%ld\n",ans);
	}
}