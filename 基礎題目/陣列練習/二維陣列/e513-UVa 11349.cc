/* 對稱的定義：
 * 對稱矩陣所有元素都是非負的並且相對於該矩陣的中心對稱。
 * 任何其他矩陣都被認為是非對稱的。
 * 二維陣列的位置對應關係, 注意邊長是奇數偶數時做法略不同
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=300;
const int MaxN=100;
long mat[MaxN][MaxN];
int main(){
	char output[2][15]={"Non-symmetric","Symmetric"};
	char ss[5];
	int caseT, N;
	scanf("%d",&caseT);
	
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%s %s %d\n",ss,ss,&N);
		bool AnyNegative=false;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				scanf("%ld",&mat[i][j]),
				AnyNegative|=(mat[i][j]<0);
		if(AnyNegative){
			printf("Test #%d: Non-symmetric.\n",caseI);
			continue;
		}
		bool IsSym=!AnyNegative;
		for(int i=0;i<(N>>1) and IsSym;i++)
			for(int j=0;j<N and IsSym;j++)
				IsSym&=(mat[i][j]==mat[N-1-i][N-1-j]);
		if(N&1)
			for(int i=0;i<(N>>1) and IsSym;i++)
				IsSym&=(mat[N>>1][i]==mat[N>>1][N-1-i]);
		printf("Test #%d: %s.\n",caseI,output[IsSym]);
	}
}