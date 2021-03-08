/* 給定Ｎ個二維平面上的點座標(座標由Ｘ座標小到大排序且不會有重複的點)，輸出最近的兩點距離？
 * 解題關鍵：分治法( Divide & Conquer ) + Branch & Bound
 * 將平面切割為左右兩側，答案的點對必定屬於三者其一：「兩點都落在左側」「兩點都落在右側」「橫跨兩側」
 * 當兩點都落在同一側時可以視為子問題，透過遞迴求解。
 * Preprocessing - 依照Ｘ座標排序(Ｙ座標無所謂) -> Brach & Bound
 * Divide - 直到範圍內剩下一點，目的是快速收斂最短距離(相鄰的Ｘ座標差最小)
 * Conquer - 左右兩側各自遞迴處理，但點數需要均攤(確保遞迴時深度最低)  
 * Combine - 利用左右兩側的最短距離 minD，求出「橫跨兩側」的解
 *           從「靠近目前中線」的點開始，在Ｘ座標距離差小於 minD 的前提下暴力法枚舉
 * Branch & Bound - 將左子問題遞迴時的 minD 傳遞給右子問題加速 combine 時的範圍 -> 0.9s/0.6s
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e6;
const int MaxP=1e7;
int pos[MaxN][2];

long DIS(long dx,long dy){ return dx*dx+dy*dy; }
void CDQ(int L,int R,long &minD){
	if(L==R) return LONG_MAX;
	int M=L+R>>1;
	CDQ(L,M,minD);
	CDQ(M+1,R,minD);
	for(int pL=M;pL>=L and DIS(pos[M+1][0]-pos[pL][0],0)<minD; pL-=1)
		for(int pR=M+1;pR<=R and DIS(pos[pR][0]-pos[pL][0],0)<minD; pR+=1)
			minD=min(minD,DIS(pos[pR][0]-pos[pL][0],pos[pR][1]-pos[pL][1]));
	return minD;
}
int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%d %d\n",&pos[i][0],&pos[i][1]);
	long minD=LONG_MAX;
	CDQ(0,N-1,minD);
	printf("%.4lf\n",sqrt(minD));
}