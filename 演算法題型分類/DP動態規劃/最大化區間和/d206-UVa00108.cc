/* 給定Ｎ×Ｎ的二維陣列矩陣，輸出最大化(矩形)區間和？
 * 降維作法：固定一個維度做動態規劃：Ｏ(Ｎ)取得固定某一段高度時的最大區間和。
 *         另一個維度利用前綴和枚舉起點和終點可以O(1)取得這個區間內的連續和。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
int col_s[MaxN][MaxN];
int N, ans;
void RowDP(int st,int ed,int sum=0){
	for(int i=0;i<N;i++){
		if(sum<0) sum=0;
		sum+=(st>=0)? col_s[ed][i]-col_s[st][i]: col_s[ed][i];
		ans=max(ans,sum);
	}
}
int main(){
	while(scanf("%d",&N)!=EOF){
		ans=0;
		for(int i=0;i<N;i++)
			scanf("%d",&col_s[0][i]);
		RowDP(-1,0);
		for(int i=1;i<N;i++){
			for(int j=0;j<N;j++){
				scanf("%d",&col_s[i][j]);
				col_s[i][j]+=col_s[i-1][j];
			}
			RowDP(-1,i);
			for(int j=i-1;j>=0;j--)
				RowDP(j,i);
		}
		printf("%d\n",ans);
	}
}