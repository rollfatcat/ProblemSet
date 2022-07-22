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
