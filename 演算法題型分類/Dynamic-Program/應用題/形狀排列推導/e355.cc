/* 給定Ｎ×Ｍ的方格地圖，輸出正方形和長方形的數量？長方形定義＝鄰邊不相等
 * 形成正方形/長方形的邊必須平行於方格，對照 d903 (若可不需平行時...)
 * 正方形＝Ｎ*Ｍ+(N-1)*(M-1)+(N-2)*(M-2)+...＝[ Ｎ*Ｎ+(N-1)*(N-1)+...+1 ]+(M-N)*(N+N-1+N-2+...)
 * 長方形＝排容(反向扣除)＝(N+N-1+N-2+...)*(M+M-1+M-2+...)-正方形數量
 * 解題核心：因為 MaxＱ高達９e4個，無法依序累加且Ｎ和Ｍ為兩個維度也無法離線查詢，需要根據上述推導公式Ｏ(1)的計算出結果。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=9e4;
const int MaxN=1e4;
int main(){
	long N, M;
	while(scanf("%ld %ld\n",&N,&M)!=EOF){
		if(N>M) swap(N,M);
		long SQR=N*(N+1)*( (N<<1)+1 )/6+(M-N)*( N*(N+1)>>1);
		printf("%ld %ld\n",SQR,(N*(N+1)>>1)*(M*(M+1)>>1)-SQR );
	}
}

