/* 給定Ｒ×Ｃ個黑色磁磚，輸出對應排列方式下需要的白色磁磚個數？
 * 排列規則：六角戰棋包圍黑色磁磚的方式。
 * 解題關鍵：排列規則
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxM=1e3;

int main(){
	int R, C;
	while( scanf("%d %d\n",&R,&C)!=EOF )
		printf("%d\n",3*R*C+2*R+C);
	
}