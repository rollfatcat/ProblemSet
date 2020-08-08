/* 給定數筆測資，每筆包含Ｎ(數列長度)和Ｎ個數字，依規定選取後能形成的有序數列最長是多少？
 * 依序給定數字時可選擇 (1)接在目前選定的數列前面(數值必須大於最前端的數字) 
 *                   (2)接在目前選定的數列後面(數值必須小於最後端的數字)
 *                   (3)捨棄
 * 解題關鍵：動態規劃的 LIS＋LDS
 * 試著以每個車廂當作中心點( 由後往前做 LIS 和 LDS )，代表以該車廂為中心點時能形成的最長長度。
 * 為何要由後往前？保持前後看到目前車廂時可以接或不接的能力，所以需要捨棄目前第ｉ個車廂前的所有車廂
 * LIS 和 LDS 陣列紀錄的長度 代表 以該車廂為"起點"時能找到的 LIS/ LDS 長度 
 *                                     ^^^^^ 以往紀錄的是以該車廂為"結尾"，所以狀態轉移方式略不同
 *       9   1   3   8   4   5  10   7   6
 * LIS   2   5   4   2   3   2   1   1   1  // 以這個數字為起點的LIS
 * LDS   4   1   1   3   1   1   3   2   1  // 以這個數字為起點的LDS
  * +)   5   5   4   4   3   2   3   2   1  // 以這個數字為中心能形成的最長長度＝LIS+LDS
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e3;
int num[MaxN];
int LIS[MaxN];
int LDS[MaxN];

int main(){
  int Q, N;
  
  scanf("%d\n",&Q);
  while(Q-->0){
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
	  scanf("%d\n",&num[i]);
	/* 枚舉每個車廂為中心點，由後往前找以該車廂為起點形成的 LIS 和 LDS */
	for(int i=N-1;i>=0;i--){
	  LIS[i]=LDS[i]=1;
	  for(int j=i+1;j<N;j++){
	  	if(num[j]>num[i])
	  	  LIS[i]=max(LIS[i],LIS[j]+1);
	  	if(num[j]<num[i])
	  	  LDS[i]=max(LDS[i],LDS[j]+1);
	  }
	}
	int ans=0;
	for(int i=0;i<N;i++)
	  ans=max(ans,LIS[i]+LDS[i]-1);
	printf("%d\n",ans);
  }
}