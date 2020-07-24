/* 給定兩個數列的狀態轉移，輸出兩個數列中第Ｎ項的數值
 * F(Ｎ)
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=3e4+1;
int  F[MaxN]={0,1};
long G[MaxN]={0,1};
int main(){
	
	for(int n=2;n<=MaxN;n++)
		F[n]=n+F[n-1],
		G[n]=F[n]+G[n-1];
	for(int n;scanf("%d\n",&n)!=EOF;)
		printf("%d %ld\n",F[n],G[n]);
}