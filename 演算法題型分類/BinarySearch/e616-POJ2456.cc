/* 最大化最小距離：標準二分法題型
 * 甜蜜點：求出『剛好無法』的最小整數, 所以答案是所求的數值-1
 * 初始化：因為是『剛好無法』所以範圍內的最小值是1, 最大值是兩個端點差＋1
 * 71%：最大值的上限只設定為兩端點差值
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int N, C;
int pos[MaxN]; // ２≤Ｃ≤Ｎ

bool IsSafe(int R,int cnt=1){
	int now=pos[0];
	for(int i=1;i<N;i++){
		if(pos[i]-now>=R)
			cnt++, 
			now=pos[i];
		if(cnt>=C)
			return true;
	}
	return false;
}
int main(){
	
	scanf("%d %d\n",&N,&C);
	for(int i=0;i<N;i++)
		scanf("%d",&pos[i]);
	sort(pos,pos+N);
	int nL=1, nR=pos[N-1]-pos[0]+1;
	for(int nM; nL<nR; (IsSafe(nM))?nL=nM+1: nR=nM)
		nM=nL+nR>>1;
	printf("%d\n",nL-1);
}