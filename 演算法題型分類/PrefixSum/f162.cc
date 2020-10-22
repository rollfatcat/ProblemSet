/* 給定一個二維矩陣Ｍ×Ｎ和Ｋ，輸出矩形內總和最接近Ｋ但不大於Ｋ的值？
 * 直覺方法：前綴和＋爬行法/二分搜尋法，但數字包含負數會導致後者失效。
 *                爬行法的精神在於"逼近"，枚舉移動後面指標搭配前面指標後移時數字減低(但如果丟掉的是負數則失效)
 *                二分搜尋法只能適用於非嚴格遞增的數列，但負數會讓前綴和形成的數列不保有前述的性質
 * 解題關鍵：題目保證 Ｍ≦50 ... Ｍ×Ｍ×Ｎ×㏒Ｎ
 *         概念上類似 d206-UVa00108 的降維作法：固定一個維度做前綴和查詢，另一個維度枚舉起點和終點
 * 		   前綴和查詢：set.lower_bound()... 實現㏒Ｎ找逼近值
 * 		   從第０個位置累加到現在第ｉ個位置的連續區間和 preS-[ 之前出現過的所有前綴和 preS ] ≦ Ｋ
 *         從第０個位置累加到現在第ｉ個位置的連續區間和 preS−Ｋ ≦ [ 之前出現過的所有前綴和 preS ] 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxK=1e9;
const int MaxM=5e1;
const int MaxMN=3e5;
const int MaxV=3e3;
const int INF=1<<30;
int N, M, K, ans;
vector<int> col_s[MaxM];

void PreFixSum(int st,int ed,int preS=0){
	set<int> memo;
	set<int>::iterator it;
	memo.insert(0);
	for(int i=0;i<N;i++){
		preS+=(st>=0)? col_s[ed][i]-col_s[st][i]: col_s[ed][i];
		it=memo.lower_bound(preS-K);
		if(it!=memo.end())
			ans=max(ans,preS-*it);
		memo.insert(preS);
	}
}
int main(){
	
	scanf("%d\n%d %d\n",&K,&M,&N);
	ans=(K>=0)? 0: -INF;
	for(int v,j=0;j<N;j++)
		scanf("%d",&v), col_s[0].push_back(v);
	PreFixSum(-1,0);
	for(int i=1;i<M;i++){
		for(int v,j=0;j<N;j++)
			scanf("%d",&v),col_s[i].push_back(v+col_s[i-1][j]);
		PreFixSum(-1,i);
		for(int j=i-1;j>=0;j--)
			PreFixSum(j,i);
	}
	printf("%d\n",ans);
}