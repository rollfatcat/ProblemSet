/* 給定Ｄ(間隔寬)和Ｎ個切點位置(輸入時會按照由小到大)，
 * 只能在切點位置做分割，必須保證每段的長度不超過規定的間隔寬，輸出最少分割的段數？
 * 解題核心：爬行法，類似線段覆蓋問題。
 * 目前切點的超過容許範圍時，需要"多一段"且更新容許的範圍(前一個位置＋Ｄ)
 */
#include<bits/stdc++.h>
using namespace std;
const int MaxN=1e4;
const int MaxD=3e3;

int main(){
	int D, N, cnt=1;
	scanf("%d %d\n",&D,&N);
	int pivot=D;
	int cut[2]={};
	scanf("%d",&cut[0]);
	for(bool now=1; --N>0; now^=1){
		scanf("%d",&cut[now]);
		if(cut[now]>pivot)
			pivot=cut[now^1]+D,
			cnt++;
	}
	printf("%d\n",cnt);
}