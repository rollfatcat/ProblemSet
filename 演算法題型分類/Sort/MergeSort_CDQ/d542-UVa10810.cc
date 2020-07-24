/* 給定Ｎ個數字，問最少需要(相鄰)交換的次數才能讓數列完成排序？
 * MergeSort 計算逆數對的數量。
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=5e5;
int num[MaxN];
int tmp[MaxN];
long ans;

void MergeSort(int nL,int nR){
	if(nL==nR) return;
	int nM=nL+nR>>1;
	MergeSort(  nL,nM);
	MergeSort(nM+1,nR);
	int p[3]={nL,nM+1,nL};
	while(p[0]<=nM and p[1]<=nR)
		if(num[p[0]]<=num[p[1]])
			tmp[p[2]++]=num[p[0]++];
		else
			tmp[p[2]++]=num[p[1]++],
			ans+= nM-p[0]+1;
	while(p[0]<=nM) tmp[p[2]++]=num[p[0]++];
	while(p[1]<=nR) tmp[p[2]++]=num[p[1]++];
	for(int i=nL;i<=nR;i++) num[i]=tmp[i];
}
int main(){
	for(int N;scanf("%d\n",&N) and N>0;){
		for(int i=0;i<N;i++)
			scanf("%d\n",&num[i]);
		ans=0;
		MergeSort(0,N-1);
		printf("%ld\n",ans);
	}
}