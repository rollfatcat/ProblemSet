/* 給定Ｎ個環狀房間(編號０-Ｎ-1, 每個房間都會有一個正整數)，給定Ｍ次任務後所在的房間位置？
 * 一開始在編號０的房間。每次任務會給予一個數字，走遍連續的房間蒐集點數直到滿足該數字後移動到下個房間作為新起點。
 * 解題關鍵：lower_bound() + prefixSum
 * 房間的數量高達 2e5 個，意味著不可能線性搜尋＝前綴和＋二分搜尋
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxM=2e4;
int prS[MaxN+1]={};
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d",&prS[i]);
		prS[i]+=prS[i-1];
	}
	int v, p=1;
	while(M-->0){
		scanf("%d",&v);
		p=(prS[N]-prS[p-1]<v)? lower_bound(prS+1,prS+N+1,v-prS[N]+prS[p-1])-prS: lower_bound(prS+1,prS+N+1,v+prS[p-1])-prS;
		p=(p==N)? 1: p+1;
	}
	printf("%d\n",p-1);
}