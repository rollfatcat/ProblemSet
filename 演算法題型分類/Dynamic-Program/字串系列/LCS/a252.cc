/* 最長共同字串(3維版本)，概念和２維版本相同
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=100+1;
int dpv[MaxN][MaxN][MaxN]={};
char ss[3][MaxN];

int main(){
	int x, y, z;
	
	scanf("%s\n%s\n%s\n",ss[0],ss[1],ss[2]);
	for(x=0;x<strlen(ss[0]);x++)
		for(y=0;y<strlen(ss[1]);y++)
			for(z=0;z<strlen(ss[2]);z++)
				dpv[x+1][y+1][z+1]=(ss[0][x]==ss[1][y] and ss[1][y]==ss[2][z])?
				  dpv[x][y][z]+1: 
				  max(dpv[x][y+1][z+1],max(dpv[x+1][y][z+1],dpv[x+1][y+1][z]));
	printf("%d\n",dpv[x][y][z]);
}