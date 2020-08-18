/* 給定Ｎ代表答案個數和Ｎ個"正確答案"的順序，輸出最長的共同子序列長度？
 * 題目給予的"順序"定義上是第ｉ個答案填寫在的位置。
 * 以下述舉例：3＝第一個數字放在數列３的位置，而非正確答案數列第一個數字是３。
 * Ex：順序是 3 1 2 4 9 5 10 6 8 7，真正的答案是 2 3 1 4 6 8 10 9 5 7 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
int org[MaxN+1];
int rhs[MaxN+1];
int LCS[MaxN+1][MaxN+1]={};

int main() {
	int N, v;
	scanf("%d\n",&N);
    /* 依據給定的順序填入答案 */
	for(int i=1;i<=N;i++)
		scanf("%d",&v), org[v]=i;
	while(scanf("%d",&v)!=EOF){
		/* 依據給定的順序填入測試 */
        rhs[v]=1;
		for(int i=2;i<=N;i++)
			scanf("%d",&v), rhs[v]=i;
		/* 標準LCS模板 */
        for(int i=1;i<=N;i++)
			for(int j=1;j<=N;j++)
				LCS[i][j]=(org[i]==rhs[j])? LCS[i-1][j-1]+1:max(LCS[i-1][j],LCS[i][j-1]);
		printf("%d\n",LCS[N][N]);
	}
}