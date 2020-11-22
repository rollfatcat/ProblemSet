/* 給定Ｎ個二維平面上的點座標(座標由Ｘ座標小到大排序且不會有重複的點)，輸出最近的兩點距離？
 * 解題關鍵：座標已經排序 → 分治法(CDQ)
 * 固定某個點時，該點若要和Ｘ座標間隔較遠的點計算距離時為最短距離的可能性越低 ... 從中間的點開始考慮
 * 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=3e6;
const int MaxP=1e7;
int pos[MaxN][2];
 
long DIS(long dx,long dy){ return dx*dx+dy*dy; }
long CDQ(int L,int R,long &minD){
  	if(L==R)   return LONG_MAX;
	if(L+1==R) return DIS(pos[R][0]-pos[L][0],pos[R][1]-pos[L][1]);
	int M=L+R>>1;
	minD=min(minD,CDQ(  L,M,minD));
	minD=min(minD,CDQ(M+1,R,minD));
	for(int pL=M; pL>=L and DIS(pos[M+1][0]-pos[pL][0],0)<minD; pL-=1)
		for(int pR=M+1; pR<=R and DIS(pos[pR][0]-pos[pL][0],0)<minD; pR+=1)
			minD=min(minD,DIS(pos[pR][0]-pos[pL][0],pos[pR][1]-pos[pL][1]));
	return minD;
}
int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d %d\n",&pos[i][0],&pos[i][1]);
	long minD=LONG_MAX;
	printf("%.4lf\n",sqrt(CDQ(0,N-1,minD)));
}