/* 給定Ｍ個點和座標維度介於(１-Ｎ)，輸出「最短兩點」的距離？
 * 解題關鍵：暴力法
 * 題目的 Ｍ ≤ 20，直接暴力法枚舉。
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=100;
const int MaxM=20;
 
int pos[MaxM][2];
inline int distance(int x,int y){ return x*x+y*y; }
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<M;i++)
		scanf("%d %d",&pos[i][0],&pos[i][1]);
	int ans=INT_MAX;
	for(int i=0;i<M;i++)
		for(int j=i+1;j<M;j++)
			ans=min(ans,distance(pos[i][0]-pos[j][0],pos[i][1]-pos[j][1]));
	printf("%.4lf\n",sqrt(ans));
}