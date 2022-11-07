/* 給定Ｎ次的選擇，每次必須從Ａ或Ｂ中擇一的步數前進，Ｎ回合結束後能否剛好走到第Ｘ格？
 * 解題核心：動態規劃 + 滾動陣列
 * 狀態定義：on[n][x] = 在第ｎ步時「能不能」抵達第ｘ格
 * 狀態轉移：on[n][x] = on[x-1][x-A] or on[x-1][x-B]
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e2;
const int MaxX=1e4;
 
bool on[2][MaxX+1]={};
int main(){
	on[0][0]=1;
	
	int N, X, A, B;
	bool now=0;
	bool pre=1;
	
	scanf("%d %d",&N,&X);
	while(N-->0){
		scanf("%d %d",&A,&B);
		swap(now,pre);
		fill(on[now],on[now]+X+1,0);
		for(int p=A; p<=X; p++)
			on[now][p]|=on[pre][p-A];
		for(int p=B; p<=X; p++)
			on[now][p]|=on[pre][p-B];
	}
	puts((on[now][X])?"Yes":"No");
}