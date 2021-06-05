/* 給定Ｎ和Ｍ，輸出Ｎ/Ｍ的小數中循環和無法形成循環的各自長度？
 * 直覺方法：判斷是否是否出現循環時＝餘數重複出現 ... 需要紀錄每個餘數出現的位置
 * 題目盲點：記憶體上限為 32 MB( 1e7 個整數 ＝ 40MB )
 * 解題關鍵：循環小數的數學解(查閱wiki)
 * 約分後將 Ｍ＝(2^m)*(5^n)*Ｋ 的形式
 * 不循環長度＝max(m,n)，循環長度＝ minimize{e},(10^e)%Ｍ ≡ 1 ... 費馬小定理無法保證找到最小 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e7;
int main(){
	
	int caseT, N, M;
	int p2, p5, B, e;
	scanf("%d",&caseT);
	while(caseT-->0){
		// 保證 N < M
		scanf("%d %d",&N,&M); 	
		M/=__gcd(N,M);
		for(p2=0; M%2==0; p2+=1, M/=2);
		for(p5=0; M%5==0; p5+=1, M/=5);
		for(e= M!=1, B=e? 10:1; B%M>1; e+=1, B=10*B%M);
		printf("%d %d\n",max(p2,p5),e);
	}
}