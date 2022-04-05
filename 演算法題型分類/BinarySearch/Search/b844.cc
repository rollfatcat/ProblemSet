/* 給定Ｋ次按下的開關和Ｑ次查詢，對應每個查詢輸出第Ｑi個燈泡的狀態(０=暗,１=亮)
 * 按下第Ｋi號碼的開關會讓燈泡編號大於等於Ｋi的燈泡狀態"轉換"。
 * 解題關鍵：排序＋二分搜尋法的STL
 * (1) 改變燈泡開關按下的"順序"不影響最後燈泡的顯示結果
 * (2) 第Ｑi個燈泡的狀態改變次數只會受到按下開關的號碼大於等於Ｑi
 * 基於(2)可以將問題視為查詢數列中大於等於Ｑi的數字個數，而(1)的前提下可以將所有開關排序便於二分搜尋法查詢。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
const int MaxQ=2e5;
const int MaxK=INT_MAX;

int K[MaxN];
int main(){
	int N, x, Q;
	while(scanf("%d %d\n",&N,&Q)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d",&K[i]);
		sort(K,K+N);
		for(int i=0;i<N;i++)
		while(Q-->0){
			scanf("%d",&x);
			printf("%d\n", (upper_bound(K,K+N,x)-K)&1 );
		}
	}
}
/*
10 3
3 1 3 2 3 3 3 3 3 8
3 6 7
*/