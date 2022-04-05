/* 給定Ｓ, 求最小的Ｎ滿足Ｎ×(Ｎ+1)/2 >Ｓ, 並輸出Ｎ×(Ｎ+1)/2−Ｓ
 * (X) Ｓ不大，先建前綴和的表＋二分搜尋找到Ｎ
 * (v) 數學問題，直接算
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxS=1e8;
int main(){
	for(int S, N;scanf("%d\n",&S) and S;){
		N=sqrt(S<<1);
		N+= (S<<1)>=N*(N+1);
		printf("%d %d\n",(N*(N+1)>>1)-S,N);
	}
}
