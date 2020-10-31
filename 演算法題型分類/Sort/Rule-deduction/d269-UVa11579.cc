/* 給定Ｎ個邊長(實數)，問能形成最大的面積是多少？
 * 根據三角形面積的海龍公式：Area＝√ｓ(ｓ-ａ)(ｓ-ｂ)(ｓ-ｃ), ｓ=(ａ+ｂ+ｃ)/2
 * 目標：『能構成三角形』的前提下，選取的邊長越長＋任意兩邊長的差值越小越好
 * 選取的邊長越長＝排序後從最大的數字開始嘗試，任意兩邊長的差值越小＝選取連續三個數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4; // 3 ≤Ｎ≤ 10000
double L[MaxN];
int main(){
	int caseT, N;
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%lf",&L[i]);
		sort(L,L+N);
		
		double s, area=0.0;
		for(N-=3;N>=0 and L[N+2]>=L[N+1]+L[N];N--);		
        
        s=(L[N]+L[N+1]+L[N+2])/2.0;
		printf("%.2lf\n",(N>=0)? sqrt(s*(s-L[N])*(s-L[N+1])*(s-L[N+2])): 0.0);
	}
}