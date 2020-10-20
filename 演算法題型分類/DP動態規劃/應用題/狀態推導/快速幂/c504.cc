/* 給定Ｎ珠花，每珠花有(紅/橘/藍/綠/棕)５種顏色可以選擇但紅花不能種在相鄰位置，問取模後的方法數量？
 * 解題關鍵：動態規劃(狀態轉移)+快速幂次法
 * 狀態轉移：紅花不能種在相鄰位置＝狀態只會和前一次選擇的顏色有關且只考慮花是否為紅色
 *         dpv[N][0]＝dpv[N-1][1] ...
 *            第Ｎ珠的狀態是「紅色」時，第Ｎ-1珠的狀態只能是「非紅色」且第Ｎ珠選擇種１種(紅色)
 *         dpv[N][1]＝４×(dpv[N-1][0]+dpv[N-1][1])
 *            第Ｎ珠的狀態是「非紅色」時，第Ｎ-1珠的狀態可以是「紅色」和「非紅色」且第Ｎ珠選擇的顏色有４種(非紅)
 * 初始狀態：只種１珠花時狀態為[１,４]
 * 快速幂次：描述狀態轉移的矩陣＝[[０,１],[４,４]]
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=10;
const int MaxK=1e8;
const int MOD=1e9+7;
 
long mat[30][2][2]; // __lg(MaxK)=26
 
int main(){
	/* Fast-Multiply */
	mat[0][0][0]=0; mat[0][0][1]=1;
	mat[0][1][0]=4; mat[0][1][1]=4;
	for(int i=1;i<=__lg(MaxK);i++){
		mat[i][0][0]=(mat[i-1][0][0]*mat[i-1][0][0]+mat[i-1][0][1]*mat[i-1][1][0])%MOD; 
		mat[i][0][1]=(mat[i-1][0][0]*mat[i-1][0][1]+mat[i-1][0][1]*mat[i-1][1][1])%MOD;
		mat[i][1][0]=(mat[i-1][1][0]*mat[i-1][0][0]+mat[i-1][1][1]*mat[i-1][1][0])%MOD; 
		mat[i][1][1]=(mat[i-1][1][0]*mat[i-1][0][1]+mat[i-1][1][1]*mat[i-1][1][1])%MOD;
	}
 
	int caseT, N;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N); N-=1;
 
		int v[2][2]={{1,4},{}};
		bool pre=0, now=1;
		for(int i=0; N>0; i++,N>>=1){
			if((N&1)==0) continue;
			v[now][0]=(mat[i][0][0]*v[pre][0]+mat[i][0][1]*v[pre][1])%MOD;
			v[now][1]=(mat[i][1][0]*v[pre][0]+mat[i][1][1]*v[pre][1])%MOD;
			swap(pre,now);
		}
		printf("%d\n",(v[pre][0]+v[pre][1])%MOD );
	} 
}