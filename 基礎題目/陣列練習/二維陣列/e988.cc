/* 給定邊長Ｎ的正方形，依照Ｓ型的規律填入數字
 * 本題採用嚴格比對：每個數字後輸出一個空白且每筆測資後輸出一個換行
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;putchar('\n')){
		for(int i=0;i<N;i++,putchar('\n'))
			if(i&1)
				for(int j=N;j>=1;j--)
					printf("%d ",i*N+j);
			else
				for(int j=1;j<=N;j++)
					printf("%d ",i*N+j);
	}
}