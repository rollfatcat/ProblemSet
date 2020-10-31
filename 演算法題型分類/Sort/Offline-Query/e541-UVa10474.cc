/* 給定一個數列, 輸出查詢的數字是否在數列中，若存在則輸出第一個出現的位置(從1開始算)，反之輸出 "not found" 
 * 解題關鍵：離線查詢
 * 題目要求找到"第一個值"，離線查詢的指標從遞增數列移動時能確保找到的必定是第一個
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=65;
const int MaxN=1e4;
const int MaxQ=1e4;
int num[MaxN];
int qry[MaxQ];
int ord[MaxQ];
int ans[MaxQ];

bool compare(int a,int b){ return qry[a]<qry[b]; }
int main(){
  int N, Q;
  for(int caseI=1;scanf("%d %d\n",&N,&Q) and N>0;caseI++){
	  for(int i=0;i<N;i++)
	  	scanf("%d\n",&num[i]);
	  for(int i=0;i<Q;i++)
	  	scanf("%d\n",&qry[i]),
	  	ord[i]=i;
	  sort(num,num+N);
	  sort(ord,ord+Q,compare);
	  int p1=0,p2=0;
	  while(p1<N and p2<Q){
			if( qry[ ord[p2] ]<num[p1] )
				ans[ ord[p2++] ]=0;
			else if( qry[ ord[p2] ]==num[p1] )
				ans[ ord[p2++] ]=p1+1;
			else
				p1++;
		}
		while(p2<Q)
			ans[ ord[p2++] ]=0;
		printf("CASE# %d:\n",caseI);
	  for(int i=0;i<Q;i++)
	  	(ans[i]==0)? printf("%d not found\n",qry[i]): printf("%d found at %d\n",qry[i],ans[i]);
  }
}
