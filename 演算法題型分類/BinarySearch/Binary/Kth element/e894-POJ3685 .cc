/* 給定邊長Ｎ的二維矩陣 和 每個數字如何產生，求該矩陣中第Ｍ小的數字？
 * 每個位置的數字Ａ[ｉ][ｊ]＝(Ｎ-10000+ｉ)×ｉ+ｊ×(ｊ+1)
 * 問題點：如何將單調性套用到這個題目 和 第Ｍ小轉換為贏過陣列中元素個數小於Ｍ的前提下最大化猜測值？
 * 解題關鍵：二分法( 猜測第Ｍ小的數字是多少 )
 * 		第Ｍ小的數字＝目前猜測的數值贏過陣列中元素的個數小於Ｍ的前提下最大化猜測值。
 * 		計算目前猜測值在第ｉ個 Row 贏過的元素個數時可以(ｘ)二分搜尋法的STL 或是 (Ｏ)開根號逼近。
 * 			遞增的性質只存在每個 Row：固定ｉ時，(Ｎ-10000+ｉ)×ｉ可視為常數，數字隨著ｊ增加而遞增。
 * 			扣除掉每個 Row 常數的值後ｊ的值是固定的並且可以利用開根號方式逼近。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int N, M, B;
int base[MaxN];
/* 計算這一個 Row 當中贏過多少個數字：(Ｏ)開根號逼近 (ｘ)二分搜尋法的STL */
inline int RowCount(int now_v){
	if(now_v<=0) return 0;
	if(now_v> B) return N;
	int sqr=sqrt(now_v);
	return sqr+ (now_v>sqr*(sqr+1));
}
int main(){
	
	while(scanf("%d %d\n",&N,&M)!=EOF){
		/* 同個 Row 當中ｊ*(ｊ+1)的最大值*/
		B=N*(N-1);
		/* 當ｉ固定時(Ｎ-10000+ｉ)*ｉ當作基礎值的常數，計算第ｉ個 Row 的基礎值 */
		for(int i=0;i<N;i++)
			base[i]=i*(N-10000+i);
		/* 二分法 */
		int nL=INT_MIN;
		int nR=INT_MAX;
		int ans;
		while(nL<=nR){
			int nM=(nL+nR)/2;
			int count=0;
			for(int i=0;i<N;i++)
				count+= RowCount(nM-base[i]);
			if(M<=count)
				nR=nM-1;
			else
				nL=nM+1,
				ans=nM;
		}
		printf("%d\n",ans);
	}
}
