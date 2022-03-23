/* 給定Ｎ隻公蜂和Ｍ隻母蜂，每隔一天個數最多的性別會產生２倍數量的公蜂，蜜蜂會改變原本的性別，輸出第Ｋ天的公/母蜂數量？
 * 解題關鍵：動態規劃-快速幂(狀態推導)
 * 題目盲點：取個數最多的性別會產生２倍數量的公蜂，乍看之下今天的數量會需要知道昨天兩個性別的數量才能決定。
 *         但這個情況僅限於第０天轉變為第一天時，第二天之後公蜂的數量一定是會大於母蜂的
 *         其實觀察Ｋ的範圍能知道一定要使用快速幂，再來只要處理取最大值的盲點即可。
 * 實作細節：題目輸出要取模，但第０天轉變為第１天時會取最大值，這時要注意原本的數值是不是已經取模(卡#5 line2)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;
const int MaxN=INT_MAX; 
const int MaxM=INT_MAX;
const int MaxK=INT_MAX;
const int MOD=1e6+7;

long mat[31][2][2]={ {{2,1},{1,0}} };
int main(){
	for(int i=1;i<31;i++){
		mat[i][0][0]=(mat[i-1][0][0]*mat[i-1][0][0]+mat[i-1][0][1]*mat[i-1][1][0])%MOD; 
		mat[i][0][1]=(mat[i-1][0][0]*mat[i-1][0][1]+mat[i-1][0][1]*mat[i-1][1][1])%MOD;
		mat[i][1][0]=(mat[i-1][1][0]*mat[i-1][0][0]+mat[i-1][1][1]*mat[i-1][1][0])%MOD; 
		mat[i][1][1]=(mat[i-1][1][0]*mat[i-1][0][1]+mat[i-1][1][1]*mat[i-1][1][1])%MOD;
	}
	
	int caseT, K;
	long vec[2][2];
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%ld %ld %d\n",&vec[0][0],&vec[0][1],&K);
		if(K--==0){ printf("%ld %ld\n",vec[0][0]%MOD,vec[0][1]%MOD); continue; }

		vec[1][0]=((max(vec[0][0],vec[0][1])<<1)+vec[0][1])%MOD;
		vec[1][1]=vec[0][0]%MOD;
		bool pre=0, now=1;
		for(int i=0; K>0; K>>=1,i++)
			if(K&1){
				swap(pre,now);
				vec[now][0]=(mat[i][0][0]*vec[pre][0]+mat[i][0][1]*vec[pre][1])%MOD;
				vec[now][1]=(mat[i][1][0]*vec[pre][0]+mat[i][1][1]*vec[pre][1])%MOD;
			}
		printf("%ld %ld\n",vec[now][0],vec[now][1]);
	}
}