/* 給定四分樹的編碼壓縮和原始圖片的邊長(２的次方)，輸出解壓縮後的原始圖片有多少個位元１？
 * ２代表當下區間內的４個區塊不屬於同一種位元，０/１則為區間內所有位元都屬於同一種
 * 解題關鍵：遞迴
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1024;
const int MaxS=2e6;

char ss[MaxS+2];
int Recursion(int& pvt,int L,int sum=0){
	if(ss[pvt]=='0') return 0;
	if(ss[pvt]=='1') return L*L;
	sum+= Recursion(++pvt,L>>1);
	sum+= Recursion(++pvt,L>>1);
	sum+= Recursion(++pvt,L>>1);
	sum+= Recursion(++pvt,L>>1);
	return sum;
}
int main(){
	int N, pvt=0;
	scanf("%s\n%d\n",ss,&N);
	printf("%d\n",Recursion(pvt,N));
}