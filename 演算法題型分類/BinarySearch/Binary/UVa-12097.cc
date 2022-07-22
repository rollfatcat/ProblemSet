/* 給定Ｎ個派和Ｆ位好友，將派分給(Ｆ+1)人，輸出"題目限制"下最大化能得到的面積？
 * 限制：每個人均分且每個人只能拿到屬於同一個派的部分。
 * 解題關鍵：二分法
 */
#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1);
const double ESP=1e-6;
const int MaxN=1e4;
const int MaxA=1e4;
int N, F;
double area[MaxN];

inline bool compare(double a,double b){ return a>b; } 
inline bool challenge(double nA,int cnt=0){
	for(int i=0;i<N;i++)
		cnt+= (int)(area[i]/nA);
	return cnt>F;
}
int main(){
	int caseT;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&F);
		for(int i=0;i<N;i++){
			scanf("%lf",&area[i]);
			area[i]=PI*area[i]*area[i];
		}
		double nL=0.0;
		double nR=MaxA*MaxA*PI;
		double ans;
		while(nR-nL>=ESP){
			double nM=(nL+nR)/2.0;
			if( challenge(nM) )
				nL=nM+ESP, ans=nM;
			else
				nR=nM-ESP;
		}
		printf("%.4lf\n",ans);
	}
}
