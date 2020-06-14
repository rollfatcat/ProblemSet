/* 這題需要自己觀察數列的規律找到數字的公式：利用差值
 * 1 3  6 10 15 21  28  36  45
 * 1 5 14 30 55 91 140 204 285
 * 1 9 36 ....
 * 第二列＝第二列 ×1e1＋第一列
 * 第三列＝第三列 ×1e2＋第一列
 * 這題計算時不能用 pow() 會導致精確度的誤差(pow回傳型態的是double)
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxM=10;
const int MaxN=9;

long memo[MaxM][MaxN];
int main(){
	for(int x=0;x<9;x++)
		memo[0][x]=x+1;
	for(int y=1;y<10;y++)
		for(int x=0;x<9;x++)
			memo[y][x]=memo[y-1][x]*(x+1);
	for(int y=0;y<10;y++)
		for(int x=1;x<9;x++)
			memo[y][x]+=memo[y][x-1];
	long TenBase=10;
	for(int y=1;y<10;y++,TenBase*=10)
		for(int x=0;x<9;x++)
			memo[y][x]=memo[y][x]*TenBase+memo[y-1][x];
	for(int M,N;scanf("%d %d\n",&M,&N)!=EOF;)
		printf("%ld\n",memo[M-1][N-1]);
}