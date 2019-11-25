/* 各自排序白天和晚上的路線, 搭配時選定是白天從小的開始搭配晚上從大的開始
 * 若該組合有超過Ｄ時就將罰金加總
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=100;
const int MaxD=10000;
const int MaxR=5;
int main(){
	int N, D, R;
	int mrg[MaxN];
	int ngt[MaxN];
	while(scanf("%d %d %d\n",&N,&D,&R) and N){
		for(int i=0;i<N;i++)
			scanf("%d",&mrg[i]);
		for(int i=0;i<N;i++)
			scanf("%d",&ngt[i]);
		sort(mrg,mrg+N);
		sort(ngt,ngt+N);
		int sum=0, tmp;
		for(int i=0;i<N;i++)
			if(mrg[i]+ngt[N-1-i]>D)
				sum+=mrg[i]+ngt[N-1-i]-D;
		printf("%d\n",sum*R);
	}
}
