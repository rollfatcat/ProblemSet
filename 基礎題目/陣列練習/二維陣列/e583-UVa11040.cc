/* 本質是數學的代數問題, 觀察優先求出的變數後填入二維陣列中
 */
#include<bits/stdc++.h>
using namespace std;

int mat[9][9];
int main(){
	int caseT;
	scanf("%d",&caseT);
	while(caseT--){
		memset(mat,sizeof(mat),0);
		for(int i=0;i<=8;i+=2)
			for(int j=0;j<=i;j+=2)
				scanf("%d",&mat[i][j]);
		// 填空
		for(int i=2;i<=8;i+=2)
			for(int j=1;j<i;j+=2){
				mat[i][j]=(mat[i-2][j-1]-mat[i][j-1]-mat[i][j+1])>>1;
				mat[i-1][j-1]=mat[i][j-1]+mat[i][j];
				mat[i-1][ j ]=mat[i][j+1]+mat[i][j];
			}
		// 輸出
		for(int i=0;i<=8;i++,putchar('\n'))
			for(int j=0;j<=i;j++)
				printf("%d ",mat[i][j]);
	}
}