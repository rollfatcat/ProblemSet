/* 區間和(二維版本)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3+1;
const int MaxQ=1e4;
int mat[MaxN][MaxN]={};
int main(){
	int R, C, Q, U, D, L;
	while(scanf("%d %d\n",&C,&R)!=EOF){
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				scanf("%d",&mat[i][j]);
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				mat[i][j]+=mat[i][j-1];
		for(int i=1;i<=R;i++)
			for(int j=1;j<=C;j++)
				mat[i][j]+=mat[i-1][j];
		for(scanf("%d\n",&Q);Q--;)
			scanf("%d %d %d %d",&L,&R,&U,&D),
			printf("%d ",mat[D+1][R+1]+mat[U][L]-mat[D+1][L]-mat[U][R+1]);
		putchar('\n');
	}
}
