/* Ｎ個寬度為1單位的長條圖，求長條圖可以形成的最大矩形面積？
 * 解題關鍵：Divide and Conquer
 * Divide  - 將範圍內的長條圖對半分，最大矩形必定屬於{ 左子問題 / 右子問題 / 包含中間的長條柱(高度限制) }
 * Combine - 包含中間的長條柱成為這個矩形的高度限制，所以枚舉往左右擴寬時的高度
 * Stop Condition - 範圍內只存在一個長條柱時高度必定相同，能形成的矩形＝該高度
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxH=1e4;
int hgt[MaxN];
int DAC(int nL,int nR){
	if(nL==nR) 
		return hgt[nL];
	int nM=nL+nR>>1;
	int ths=max(DAC(nL,nM),DAC(nM+1,nR));
	int pL=nM-1, pR=nM+1;
	int nowH=hgt[nM];
	while(nL<=pL or pR<=nR){
		while(nL<=pL and nowH<=hgt[pL]) pL-=1; // 往左擴寬
		while(pR<=nR and nowH<=hgt[pR]) pR+=1; // 往右擴寬
		ths=max(ths,(pR-pL-1)*nowH); // 計算這次形成的矩形面積
		nowH=(pR==nR+1 or nL<=pL and hgt[pL]>hgt[pR])? hgt[pL]: hgt[pR]; // 取左右側高度較高為下一次擴寬的標準
	}
	return ths;
}
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&hgt[i]);
	printf("%d\n",DAC(0,N-1));
}