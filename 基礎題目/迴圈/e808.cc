/* 給定Ｎ個公車站、公車發車時間、抵達Ｎ個站的移動時間，輸出抵達第Ｐ站的時間
 * 詢問的第Ｐ站依據由小到大詢問直到Ｐ=0時結束查詢。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
int t[MaxN];

int main(){
	int N, start_H, start_M;
	
	scanf("%d\n%d %d\n",&N,&start_H,&start_M);
	for(int i=0;i<N;i++)
		scanf("%d\n",&t[i]);
	for(int now=0,p;scanf("%d\n",&p) and p;){
		for(;now<p;now++)
			start_M+=t[now];
		start_H=(start_H+start_M/60)%24;
		start_M%=60;
		printf("%02d:%02d\n",start_H,start_M);
	}
		
}