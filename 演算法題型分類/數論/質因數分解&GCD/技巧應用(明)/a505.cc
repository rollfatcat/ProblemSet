/* 給定Ｎ個數字，輸出數字 Xi 是否只有３個因數？
 *  N ≤ 1e6, Xi ≤ 1e14
 * 解題關鍵：質數表
 * Xi 的因數必定包含１和 Xi，代表３個因數中剩下的數字 Si
 * (1) Si 對 Xi 來說是除數也是被除數 ... Xi 為平方數。
 * (2) Si 為因數且無法分解出其他因數 ... Si 為質因數。
 * 綜合上述條件：Xi 有３個因數的條件 ... Xi 為質因數的平方數。 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e7;
bool NotP[MaxN+1]={};
int main(){
	/* 建質數表，範圍 sqrt(1e14)＝1e7 */
    for(int i=4;i<=MaxN;i+=2) 
        NotP[i]=1;
	for(int i=3;i<=sqrt(MaxN);i+=2)
		if(NotP[i]==0)
			for(int j=i; i*j<=MaxN; j+=2)
				NotP[i*j]=1;
	int caseT;
	long x, sqx;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%ld\n",&x);
		sqx=sqrt(x);
		puts( (NotP[sqx]==0 and sqx*sqx==x)?"YES":"NO");
	}
}