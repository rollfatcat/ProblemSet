/* 給定初始時１８個村莊的人數，經過Ｍ次的操作，查詢Ｑ次
 * 操作＝第ｖ個村莊在第ｔ時刻ｐ位村民(ｂ=１移出/ｂ=２移入)
 * 查詢＝輸出第ｔ時刻第ｖ1 個村莊到第ｖ2個村莊的村民總和(人口數是負數仍為合理)
 * Ｍ和Ｑ的次數極大，查詢的成本必須下降為Ｏ(1)
 * ｔ和ｖ的數值範圍不大，處理操作時直接透過二維陣列紀錄，狀態＝第ｔ個時刻第ｖ個村莊人口的變化量。
 * 二維版本的前綴和來應付查詢時的耗費成本。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=3e5;
const int MaxM=3e5;
const int MaxV=18;
const int MaxT=24;
int preS[MaxV+1][MaxT+1]={};

int main(){
	int M, Q, v, t, p, b;
	for(int i=1;i<=MaxV;i++)
		scanf("%d",&preS[i][0]),
		preS[i][0]+=preS[i-1][0];
	scanf("%d\n",&M);
	while(M-->0)
		scanf("%d %d %d %d\n",&v,&t,&p,&b),
		preS[v][t]+= (b==2)? p: -p;
	
	for(v=1;v<=MaxV;v++)
		for(t=1;t<=MaxT;t++)
			preS[v][t]+=preS[v-1][t]+preS[v][t-1]-preS[v-1][t-1];
	
	scanf("%d\n",&Q);
	while(Q-->0)
		scanf("%d %d %d\n",&v,&p,&t),
		printf("%d\n",preS[p][t]-preS[v-1][t]);
}