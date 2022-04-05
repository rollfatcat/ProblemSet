/* 題目給給定Ｎ個物品的重量、價值，Ｍ個區間，標準值Ｓ，輸出如何調整Ｗ時能得到所有區間的標準值總和給定的標準值差距最小？
 * 校準值計算方式：單一區間內的物品中重量大於等於Ｗ的價值和 ｘ 單一區間內的物品中重量只要大於等於Ｗ的數量
 * 題目出處：LUOGU-P1314 二分法估值+前綴和(價值和個數)
 * 解題關鍵：前綴和＋二分法(收斂的過程中找到最小的標準值差距，單調性和題目要求無關)
 * 問題點：區間的查詢次數過多，所以如何有效的算出區間內重量大於等於Ｗ的物品價值總和及數量？
 *        直覺是RMQ的樹狀數組，但可以發現查詢時並不會改動到原本的數據因此前綴和是更佳的選項！
 * 前綴和：有效的累加每個區間內物品重量大於等於Ｗ的價值總和及個數，每次查詢的成本降為Ｏ(1)
 * 二分法：『單調性證明』Ｗ越大所有區間的標準總和越小，反之越大。
 *        收斂過程中根據區間標準總和是否大於Ｓ決定收縮方向：
 *        (1) 等於Ｓ，不可能存在更好的誤差值，離開迴圈
 *        (2) 小於Ｓ，向左縮
 *        (3) 大於Ｓ，向右縮
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxM=2e5;
const long MaxS=1e12;

int N, M;long S;
int w[MaxN+1];
int v[MaxN+1];
int qL[MaxM];
int qR[MaxM];
long ansS=MaxS;
long PreSv[MaxN+1];
int PreCnt[MaxN+1];
inline int NextOpt(int W){
	/* 前綴和 */
	PreSv[0]=PreCnt[0]=0;
	for(int i=1;i<=N;i++)
		if(w[i]>=W){
			PreSv[i] =PreSv[i-1]+v[i];
			PreCnt[i]=PreCnt[i-1]+1;
		}else{
			PreSv[i] =PreSv[i-1];
			PreCnt[i]=PreCnt[i-1];
		}
  	/* 累加每段區間內重量大於等於Ｗ的物品價值總和及數量 */
	long nowS=-S;
	for(int i=0;i<M;i++)
		nowS+=( PreCnt[qR[i]]-PreCnt[qL[i]-1] )*( PreSv[qR[i]]-PreSv[qL[i]-1] );
	/* 收斂過程中取最小差距(絕對值) */
	ansS=min(ansS,abs(nowS));
	/* 大於Ｓ或小於Ｓ決定收縮方向 */
	return (nowS<0)? -1: nowS>0;
} 
int main(){
	
  scanf("%d %d %ld\n",&N,&M,&S);
  for(int i=1;i<=N;i++)
  	scanf("%d %d\n",&w[i],&v[i]);
  for(int i=0;i<M;i++)
  	scanf("%d %d\n",&qL[i],&qR[i]);
  /* 題目保證１ ≦ Ｗ ≦ 1e6，視為綁定二分法的範圍 */
  int nL=1, nR=MaxN;
  while(nL<=nR){
  	int nM=nL+nR>>1;
  	int opt=NextOpt(nM);
  	if(opt==0) break;
  	(opt>0)? nL=nM+1: nR=nM-1;
  }
  printf("%ld\n",ansS);
}