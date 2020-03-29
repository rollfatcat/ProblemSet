/* 給定兩個數字，輸出建構式的計算過程
 * 需要補空白處理對齊問題，直覺是模擬大數運算
 * 但數字不超過1e4可以透過log10(x)取得長度後並計算需要補的空白個數，注意log10(0)的情況
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxV=1e4; // 1 ≤ a, b ≤ 9999
inline void FillChar(int L,char ch){ for(int i=0;i<L;i++)putchar(ch); }
inline int Power10(int x){ return (x<=1)?1:ceil(log10(x)); }
int main(){
	
	int A, B;
	scanf("%d\n%d\n",&A,&B);
	int C=A*B, L=ceil(log10(C));
	
	FillChar(L-Power10(A),' '), printf("%d\n",A);
	FillChar(L-Power10(B),' '), printf("%d\n",B);
	FillChar(L,'-'),            putchar('\n');
	for(int endL=L,D;B;B/=10,endL--)
		D=B%10*A, FillChar(endL-Power10(D),' '), printf("%d\n",D);
	FillChar(L,'-'),                putchar('\n');
	printf("%d\n",C);
}