/* 給定Ｎ個圓盤(編號１-Ｎ)，這些圓盤初始起點的柱子編號 和 終點的目標柱子編號，輸出搬動最少的次數？
 * 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=30;
int now[MaxN];
int stp[MaxN];
int dpv[MaxN+1];

void Hanoi(int ths,char to,int& ans){
	if(now[ths]!=to){
		if(ths)
			Hanoi(ths-1,6-now[ths]-to,ans);
		ans+= 1<<ths;
		return;
	}
	if(ths)
		Hanoi(ths-1,to,ans);
}
int main(){
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
			ans+=1;
		}
		for(N-=1; N>=0; N-=1)
			if(pvt!=stp[N]){
				ans+= 1<<N;
				pvt=6-pvt-stp[N];
			}
		printf("%d\n",ans);
	}
}