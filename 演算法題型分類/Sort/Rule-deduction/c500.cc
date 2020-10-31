/* 給定１-Ｎ號位置和Ｋ個滑鼠對兔吉造成的傷害(每單位格造成的傷害)，兔吉坐的位置Ｍ和滑鼠間隔最少Ｆ個位置。
 * 規定：若滑鼠的位置出現在兔吉的左手邊或是兔吉持有都不會造成傷害，問Ｋ個滑鼠為兔吉帶來最少的總傷害？
 * 解題關鍵：最小化傷害＝最大化滑鼠在兔吉左手邊的位置數量 且 讓單位傷害最高的滑鼠放在越近的地方。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e7;
int main(){
	int K, N, M, F;
	while(scanf("%d %d %d %d\n",&K,&N,&M,&F)!=EOF){
		vector<int> damage(K);
		for(int i=0;i<K;i++)
			scanf("%d",&damage[i]);
		int dnt=(M-1)/F+1;
		if(dnt>=K){ puts("0"); continue; }
		sort(damage.begin(),damage.end());
		long sum=0, pos=F*dnt-M+1;
		for(int i=K-dnt-1;i>=0;i--,pos+=F)
			sum+=pos*damage[i];
		printf("%ld\n",sum);
	}
}