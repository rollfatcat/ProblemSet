/* 題目給定Ｎ件物品的重量和價值，對於每件物品只能選或不選，每次查詢時會要求要選定Ｋ個時輸出最大的平均值？
 * 解題關鍵：二分法
 * 問題點 :(Ｘ) 物品數量最多 1000 個，不可能針對物品枚舉選或不選
 *        (Ｘ) 背包問題的動態規劃解法也無法套用(如何定義狀態？)
 *        (Ｘ) 貪婪法：從平均值高的物品開始挑
 *        (Ｏ) 如何應用二分法的"單調性"在最大平均值(猜平均值，猜的太高或是太低)
 * Ｃ(ｘ):= 可以選擇使得單位重量的價值不小於ｘ，因此原本的問題可以視為時最大化Ｃ(ｘ)。
 * 假設我们選了某些物品的集合Ｓ，單位重量的價值的計算方式：∑ｖ[i]/∑ｗ[i], ｉ∈Ｓ，
 * 判斷是否存在一組集合Ｓ大於等於猜測值Ｃ(ｘ)，滿足 ∑ｖ[i]/∑ｗ[i] ≧ Ｃ(ｘ) ... ∑(ｖ[i]-Ｃ(ｘ)×ｗ[i]) ≧ ０
 * 上述的不等式可以針對每組的ｖ[i]-Ｃ(ｘ)×ｗ[i]，從大到小選出前Ｋ個的和不小於０。
 */
#include<bits/stdc++.h>
using namespace std;

const double ESP=1e-6;
const int MaxN=1e3;
const int MaxQ=50;
int N, Q, K;
int w[MaxN];
int v[MaxN];
double rem[MaxN];
inline bool challenge(double testD){
	for(int i=0;i<N;i++)
		rem[i]=v[i]-testD*w[i];
	sort(rem,rem+N);
	double sumD=0.0;
	for(int i=1;i<=qv;i++)
		sumD+=rem[N-i];
	return sumD>=-ESP;
}
int main(){
	double minD=2e9;
	double maxD=0.0;
	
	scanf("%d %d\n",&N,&Q);
	for(int i=0;i<N;i++){
		scanf("%d %d\n",&w[i],&v[i]);
		double nowD=1.0*v[i]/w[i];
		minD=min(minD,nowD);
		maxD=max(maxD,nowD);
	}
	while(Q-->0){
		scanf("%d\n",&K);
		double nL=minD;
		double nR=maxD;
		double ans;
		while(nR-nL>=ESP){
			double nM=(nL+nR)/2.0;
			if( challenge(nM) )
				nL=nM+ESP, ans=nM;
			else
				nR=nM-ESP;
		}
		printf("%.2lf\n",ans);
	}
}