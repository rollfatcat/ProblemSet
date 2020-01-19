/* 給定一張踩地雷的地圖，若該格不是地雷時輸出這個格子周圍的地雷數量(周圍的定義是８格)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100;
int main(){
	int N, M;
	char mapss[MaxN][MaxN+2];
	char cnt[MaxN][MaxN+2];
	for(int caseI=1;scanf("%d %d\n",&N,&M) and N;caseI++){
		for(int i=0;i<N;i++){
			scanf("%s\n",mapss[i]);
			for(int j=0;j<M;j++)
				cnt[i][j]='0';
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if(mapss[i][j]=='*'){
					if(  i>0) cnt[i-1][j]++;
					if(i+1<N) cnt[i+1][j]++;
					if(  j>0) cnt[i][j-1]++;
					if(j+1<M) cnt[i][j+1]++;
					if(  i>0 and   j>0) cnt[i-1][j-1]++;
					if(i+1<N and   j>0) cnt[i+1][j-1]++;
					if(  i>0 and j+1<M) cnt[i-1][j+1]++;
					if(i+1<N and j+1<M) cnt[i+1][j+1]++;
				}
		if(caseI>1) putchar('\n');
		printf("Field #%d:\n",caseI);
		for(int i=0;i<N;i++,putchar('\n'))
			for(int j=0;j<M;j++)
				putchar((mapss[i][j]=='*')?'*':cnt[i][j]);
	}
}