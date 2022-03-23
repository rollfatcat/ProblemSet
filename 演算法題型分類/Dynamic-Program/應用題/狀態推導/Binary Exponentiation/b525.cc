/* 給定Ｍ隻雄蜂和Ｆ隻雌蜂，經過Ｋ秒後的蜜蜂數量(假設蜜蜂不會死亡)？
 * 每過１秒雄蜂會轉變性別為雌蜂且每隻雌蜂可以生下一隻雄蜂。
 * 解題關鍵：動態規劃＋快速幂次法
 * 題目已經說明狀態轉移的方式，但 MaxＫ＝2e7 所以需要快速幂次。 
 * 快速幂次：描述狀態轉移的矩陣＝[[０,１],[１,１]]
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e3;
const int MaxK=2e7;
const int MOD=1e8+7;
 
long mat[25][2][2]; // __lg(MaxK)=24
 
int main(){
	/* Fast-Multiply : 2-base */
	mat[0][0][0]=0; mat[0][0][1]=1;
	mat[0][1][0]=1; mat[0][1][1]=1;
	for(int i=1;i<=__lg(MaxK);i++){
		mat[i][0][0]=(mat[i-1][0][0]*mat[i-1][0][0]+mat[i-1][0][1]*mat[i-1][1][0])%MOD; 
		mat[i][0][1]=(mat[i-1][0][0]*mat[i-1][0][1]+mat[i-1][0][1]*mat[i-1][1][1])%MOD;
		mat[i][1][0]=(mat[i-1][1][0]*mat[i-1][0][0]+mat[i-1][1][1]*mat[i-1][1][0])%MOD; 
		mat[i][1][1]=(mat[i-1][1][0]*mat[i-1][0][1]+mat[i-1][1][1]*mat[i-1][1][1])%MOD;
	}
 
	int K, v[2][2];
	while(scanf("%d %d %d\n",&v[0][0],&v[0][1],&K)!=EOF){
		bool pre=0, now=1;
		for(int i=0; K>0; i++,K>>=1){
			if((K&1)==0) continue;
			v[now][0]=(mat[i][0][0]*v[pre][0]+mat[i][0][1]*v[pre][1])%MOD;
			v[now][1]=(mat[i][1][0]*v[pre][0]+mat[i][1][1]*v[pre][1])%MOD;
			swap(pre,now);
		}
		printf("%d\n",(v[pre][0]+v[pre][1])%MOD );
	}
}