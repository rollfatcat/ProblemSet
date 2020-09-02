/* 排序後，問從兩個數列各自任取一個數字的和能超過10的最多#配對
 * 題目保證輸入的數值範圍介於１≤ｖ≤９所以可用 CountSort 降低記憶體耗量( 0.2s/324KB vs 0.2s/1.1MB )
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=10;
const int MaxN=1e5;
const int Threshold=10;
int v, cnt[2][10]; // １≤ｖ≤９
int main(){
	for(int N;scanf("%d\n",&N) and N;){
		fill(cnt[0],cnt[0]+10,0);
		for(int i=0;i<N;i++) 
			scanf("%d",&v), cnt[0][v]++;
		fill(cnt[1],cnt[1]+10,0);
		for(int i=0;i<N;i++) 
			scanf("%d",&v), cnt[1][v]++;
 
		int pair=0;
		for(int i0=2,i1=9; i0<=9 and i1>=1;){
			if(i0+i1<=Threshold){ i0++; continue; }
			v=min(cnt[0][i0],cnt[1][i1]);
			cnt[0][i0]-=v; if(cnt[0][i0]==0) i0++;
			cnt[1][i1]-=v; if(cnt[1][i1]==0) i1--;
			pair+=v;
		}
		printf("%d %d\n",pair,pair*200);
	}
}