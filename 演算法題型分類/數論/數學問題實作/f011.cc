/* 給定一個Ｎ項的方程式，問線上的一點Ｐ(a,b)切線與Ｘ軸的交點？
 * 通過P點的切線斜率＝該方程式的一次微分
 * 觀察測資的輸入範圍：(1) 1≤Ｎ≤15，每項係數Ck∈Z，|Ck|≤100 (2)切點P(a,b)的a，a∈Z，|a|≤100
 * 可知道計算時運算範圍最大是1e32，需要__int128紀錄。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=1e4;
const int MaxN=15;
const int MaxV=1e2;
int coff[MaxN+1];

inline bool IsZero(double x){ return abs(x)<=1e-6; }
int main(){
	int T, N, a;
	__int128 b, x, M;
	scanf("%d\n",&T);
	while(T--){
		scanf("%d\n",&N);
		for(int i=N;i>=0;i--)
			scanf("%d",&coff[i]);
		scanf("%d\n",&a);
		// 斜率＝方程式的一次微分
		M=0, x=1, b=coff[0];
		for(int i=1;i<=N;i++)
			M+=i*x*coff[i],
			x=x*a,
			b+=x*coff[i];
			
		if(M==0){ 
			puts( (b==0)?"It can sleep everywhere!":"It cannot sleep!");
		}else
			printf("(%.3lf,0)\n",a-1.0*b/M);
	}
}