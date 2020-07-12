/* 給定Ｎ個人繞圓移動(環長Ｘ)和移動速度Ｖ，每個人的初始位置和移動方向(０順時針/１逆時針)，輸出一秒後任選兩人的最大的間距？
 * 碰撞處理：兩人相遇後會改變轉向
 * Special Case：(1) Ｎ=1 (2)操場為環形所以端點兩個位置視為相鄰
 * 解題關鍵：ＡＢ碰撞不影響位置，只是交換兩者停下位置，換句話說是否發生碰撞不影響最終所有人停下的位置。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=3e4;
const int MaxN=1e6;
int pos[MaxN];

int main(){
	
	int Q, N, X, V, D;
	
	scanf("%d\n",&Q);
	while(Q-->0){
		scanf("%d %d %d\n",&N,&X,&V); V%=X;
		for(int i=0;i<N;i++){
			scanf("%d %d\n",&pos[i],&D);
			(D)? pos[i]-=V : pos[i]+=V;
			if(pos[i]>=X) pos[i]-=X;
			if(pos[i]<0 ) pos[i]+=X;
		}
		sort(pos,pos+N);
		int dis=0;
		for(int i=1;i<N;i++)
			dis=max(dis,pos[i]-pos[i-1]);
		printf("%d\n",max(dis,X-pos[N-1]+pos[0]));
	}
}
