/* 給定Ｎ個數字(A1,A2,...,An)和指定的群組數Ｍ，輸出符合條件的組合的個數？  
 * 條件：將編號１-Ｎ填入 A1,A2,..., An 的位置上(那格是０代表可以填入)剛好形成Ｍ個群組。
 * 說明：Ｎ＝５, ０ １ ０ ２ ０ ... １２這兩個號碼已經寫入，所以未出現過的３４５可以填入格子是０的位置。
 * 解題關鍵：StirlingNumber I (第一類斯特林數列)
 * StirlingNumber I  : Ｎ個數字分Ｋ個循環非空圓圈      ... ƒ(N)=ƒ(N-1,K-1)+(Ｎ-1)×ƒ(N-1,K)
 * StirlingNumber II : Ｎ個數字分Ｋ個組(不考慮組內循環) ... ƒ(N)=ƒ(N-1,K-1)+(Ｋ-1)×ƒ(N-1,K)
 * 若存在一組閉鎖循環的團體代表會佔用到群組數Ｍ的一個名額，Ｍ-=1
 * 只需要考慮開放循環的團體個數(０的個數)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e4;
const int MaxN=1e3;
const int MOD=1e6+7;

int N, M;
/* 第一類斯特林(StirlingNumber)：Ｎ個數字分Ｋ個循環非空圓圈 */
int STIR[MaxN+1][MaxN+1]={};
int nxt[MaxN+1];

int main(){
	/* StirlingNumber I - BottomUp*/
	STIR[0][0]=STIR[1][1]=1;
	for(int n=2; n<=MaxN; n++){
		STIR[n][n]=1;
		for(int k=1;k<n;k++)
			STIR[n][k]=(STIR[n-1][k-1]+(n-1)*STIR[n-1][k])%MOD;
	}
	
	int caseT, zeroCnt;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&M);
		zeroCnt=0;
		for(int i=1;i<=N;i++){
			scanf("%d",&nxt[i]);
			zeroCnt+= nxt[i]==0;
		}
		for(int ths=1;ths<=N;ths++){
      int rhs, now=nxt[ths];
			/* 類似指標的想法：
       * 把 nxt[now] 設定為０代表之後再讀取時就停止，但這麼一來無法透過 nxt[now] 取得下個位置。
       * 需要暫存 nxt[now] 的值才得位移到下次位置。
       */
      for(nxt[ths]=0; now>0; now=rhs){
				rhs=nxt[now];
				nxt[now]=0;
			}
      /* 存在一個封閉的單向環(路徑上不存在０)時需要消耗一個群組個數(無法加入新的數字) */
      M-= now==ths;
		}
		printf("%d\n",(M>=0)? STIR[zeroCnt][M]: 0);
	}
}