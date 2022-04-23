/* N ≤ X = a^3 + b*a^2 + a*b^2 + b^3 ，存在一組整數解(a,b)可以描述Ｘ滿足 N ≤ X 時的最小Ｘ
 * 解題關鍵：枚舉ａ，對ｂ做二分搜
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxN=1e18;
int main(){
	long N;
	scanf("%ld",&N);
	
	long A, B=-1;
	long ans=MaxN+1;
	do{
		B++;
		long L=B;
		long R=1e6;
		while(L<=R){
			long M=L+R>>1;
			long v=M*M*M+M*B*B+M*M*B+B*B*B;
			if(N<=v){
				ans=min(ans,v);
				A=M;
				R=M-1;
			}else
				L=M+1;
		}
	}while(A>B);
	printf("%ld",ans);
}