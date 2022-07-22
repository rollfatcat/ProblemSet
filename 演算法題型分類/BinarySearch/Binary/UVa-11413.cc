/* 給定Ｎ瓶牛奶，以及Ｋ個容器(相同容量)，容積至少要"多少"才能使得只用Ｎ瓶牛奶裝完？
 * 而裝的時候有幾個規則：第一瓶牛奶瓶倒入容器後才能換第二瓶而且每瓶牛奶只能到入同個容器
 * (因此如果該容器還有空間但不夠裝完這瓶牛奶的話，就只能換下個容器)。
 * 解題關鍵：二分法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxA=1e6;
int N, K;
int num[MaxN];

inline bool challenge(long testR){
	int cnt=K-1;
	long rem=testR;
	for(int i=0;i<N;i++){
		if(rem<num[i]){
			if(cnt==0)
				return false;
			cnt--;
			rem=testR;
		}
		rem-=num[i];
	}
	return true;
}
int main(){
	while(scanf("%d %d\n",&N,&K)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		int nL=0;
		int nR=0;
		for(int i=0;i<N;i++){
			nL=max(nL,num[i]);
			nR+=num[i];
		}
		/* 二分法 */
		int ans;
		while(nL<=nR){
			int nM=nL+nR>>1;
			if( challenge(nM) )
				nR=nM-1, ans=nM;
			else
				nL=nM+1;
		}
		printf("%d\n",ans);
	}
}
