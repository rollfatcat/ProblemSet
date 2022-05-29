/* 給定Ｎ個數字，輸出數列中不會被數列其他數字整除的個數？
 * 解題關鍵：利用篩法判斷“整除”：只需要設定該數字倍數的狀態
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxA=1e6;

int num[MaxN+1];
bool  out[MaxN+1]={};
bool NotP[MaxA+1]={};
int main(){
	int N;
	
	scanf("%d",&N);
	for(int n=1; n<=N; n++)
		scanf("%d",&num[n]);
	num[0]=0;
	sort(num+1,num+1+N);
	for(int n=1; n<=N; n++){
        // 和前一個數字一樣時，該數字不屬於答案
		if( num[n-1]==num[n] ){ out[n-1]=out[n]=1; continue; }
		// 屬於某個數字的倍數(能被整除)
        if( NotP[num[n]] ){ out[n]=1; continue; }
		for(int v=num[n]; v<=MaxA; v+=num[n])
			NotP[v]=1;
	}
	int ans=0;
	for(int n=1; n<=N; n++)
		ans+= !out[n];
	printf("%d",ans);
}