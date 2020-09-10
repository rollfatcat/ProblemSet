/* 題目給定Ｎ個露營區的半徑和Ｋ頂帳篷，帳篷排列在露營區圓周且相距等寬，在最大化相距寬度的前提下輸出每個營區擺放的帳篷數量？
 * 解題關鍵：二分法
 *    猜測值＝間隔寬度
 *    單調性：間隔越寬能放的帳篷越少，反之間隔越窄放的帳篷越多
 *    滿足放滿Ｋ頂帳篷的前提下找到最大的間隔寬度，之後依照題目要求計算每個營區能放的帳篷數量。
 */
#include<bits/stdc++.h>
using namespace std;

const double ESP=1e-6;
const double PI=acos(-1);
const int MaxN=10;
int N, K;
double R[MaxN];

inline bool challenge(double testR,int cnt=0){
	for(int i=0;i<N;i++)
		cnt+= R[i]/testR;
	return cnt>=K;
}
int main(){
	while(scanf("%d %d\n",&N,&K)!=EOF and N>0){
		for(int i=0;i<N;i++){
			scanf("%lf",&R[i]);
			R[i]*=2.0*PI;
		}
		double nL=0.0;
		double nR=INT_MAX;
		double ans;
		while(nR-nL>=ESP){
			double nM=(nL+nR)/2.0;
			if( challenge(nM) )
				nL=nM+ESP, ans=nM;
			else
				nR=nM-ESP;
		}
		for(int i=0;i<N;i++)
			printf("%d ",(int)(R[i]/ans));
		putchar('\n');
	}
}
