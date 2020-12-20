/* 有限背包的變形題(有限背包＋無限背包)
 * 給定６種貨幣的個數和需要支付的＄，最小化交易中使用的貨幣個數
 * 題目允許『找零的方式』：95＝50+20+20+5＝100-5
 * ６種貨幣的個數＝有限背包，找的零錢＝無限背包
 * 保證支付的＄少於５元，建表時的最大上限＝５+１(第二大的面值)
 */
#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;
const int MaxUV=120;
const int MaxV=100; // 小於５的實數，交易金額永遠是5c的倍數
const int coin[6]={1,2,4,10,20,40}; // 5c、10c、20c、50c、1、2
int cnt[6];
int DP[2][MaxUV+1]={};
vector<int> UDP(MaxUV+1,INF);

int main(){
	UDP[0]=0;
	for(int t=0;t<6;t++)
		for(int v=coin[t];v<=MaxUV;v++)
			UDP[v]=min(UDP[v],UDP[v-coin[t]]+1);
	int cash, cent, ans;
	while(scanf("%d %d %d %d %d %d",&cnt[0],&cnt[1],&cnt[2],&cnt[3],&cnt[4],&cnt[5])!=EOF and cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]>0){
		scanf("%d.%d\n",&cash,&cent);
		cash*=20, cent=cash+cent/5;
		
		int pre=0,now=1;
		for(int i=1;i<=MaxUV;i++) 
			DP[0][i]=INF;
		for(int t=0;t<6;t++){
			for(int v=1;v<=MaxUV;v++){
				DP[now][v]=DP[pre][v];
				for(int k=1;k<=cnt[t] and v-k*coin[t]>=0;k++)
					DP[now][v]=min(DP[now][v],DP[pre][v-coin[t]*k]+k);
				}
			swap(now,pre);
		}
		ans=DP[pre][cent];
		for(int v=MaxUV;v>cent;v--)
			ans=min(ans,DP[pre][v]+UDP[v-cent]);
		printf("%3d\n",ans);
	}
}