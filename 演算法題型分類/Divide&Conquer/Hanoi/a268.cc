#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MOD=1e9+7;
int dpv[MaxN+1];
int now[MaxN];
int stp[MaxN];

void Hanoi(int ths,char to,int& ans){
	if(now[ths]!=to){
		if(ths)
			Hanoi(ths-1,6-now[ths]-to,ans);
		ans=(ans+dpv[ths])%MOD;
		return;
	}
	if(ths)
		Hanoi(ths-1,to,ans);
}
int main(){
	/* tabulation */
	dpv[0]=1;
	for(int i=1;i<=MaxN;i++)
		dpv[i]=(dpv[i-1]<<1)%MOD;

	int N, ans, pvt;
	while(scanf("%d\n",&N)!=EOF and N>0){
		for(int i=0;i<N;i++)
			scanf("%d",&now[i]);
		for(int i=0;i<N;i++)
			scanf("%d",&stp[i]);
		int ans=0;
		/* 做第一次的圓盤位移 */
		for(N-=1; N>=0 and now[N]==stp[N]; N-=1);
		if(N>0){
			Hanoi(N-1,6-now[N]-stp[N],ans);
			pvt=6-now[N]-stp[N];
		}
		if(N>=0)	
			ans=(ans+1)%MOD;
		
		for(N-=1; N>=0; N-=1)
			if(pvt!=stp[N]){
				ans=(ans+dpv[N])%MOD;
				pvt=6-pvt-stp[N];
			}
		printf("%d\n",ans);
	}
}
