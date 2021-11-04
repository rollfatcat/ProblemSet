/* 給定Ｎ(Ｎ≤ 1e7)個相異的數字(Ａ≤ 1e7)，依照「規則」不斷縮減範圍直到範圍內剩下一個數字後輸出。
 * 規則：找到目前區間內的最小值，依照最小值的位置將區間拆分為左右邊(接不包含該位置)的總合中選擇較大者為新區間。
 * 解題關鍵：離線處理(更新順序：數字由小到大)，過程中只需要考慮切點落在「區間內」
 * 解題細節：避免使用遞迴導致記憶體問題(遞迴會卡 stack)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e5;
int ord[MaxN+1];
int num[MaxN+1];
long prS[MaxN+1];

int main(){
	
	int N;
	scanf("%d",&N);
	prS[0]=0;
	for(int i=1;i<=N;i+=1){
		scanf("%d",&num[i]);
		ord[i]=i;
		prS[i]=prS[i-1]+num[i];
	}
	sort(ord+1,ord+N+1,[&](int ths,int rhs){
		return num[ths]<num[rhs]; });
	// avoid Recursion
	int nL=1;
	int nR=N;
	for(int i=1; nL<nR; i+=1){
		if(ord[i]<nL or nR<ord[i]) continue;
		( prS[nR]-prS[ord[i]]>=prS[ord[i]-1]-prS[nL-1] )? nL=ord[i]+1: nR=ord[i]-1;
	}
	printf("%d\n",num[nL]);
}