/* 給定整體空間的範圍(ＲxＣxＨ)和Ｎ個"障礙點"，輸出所有的立方體(不可包含障礙點)的數量？
 * 解題關鍵：動態規劃 - 三維的最大正方形邊長
 * 狀態定義：以(a,b,c)往３個維度延伸的能形成最大的立方體邊長 和 立方體數量
 * 狀態轉移：對周圍延伸一格範圍內的７格作狀態轉移，邊長取最小值+1，數量取前綴和
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxL=300+1;
const int MaxN=1e5;
int cnt[MaxL][MaxL][MaxL]={};
int len[MaxL][MaxL][MaxL]={};
int min_len(int a,int b,int c){
	return min(
		min( min(len[a-1][b-1][c],len[a][b][c-1]),
	       min(len[a-1][b][c-1],len[a][b-1][c])),
	  min( min(len[a][b-1][c-1],len[a-1][b][c]),len[a-1][b-1][c-1]) );
}
int main(){
	int A, B, C, N, x, y, z;
	
	scanf("%d %d %d %d",&A,&B,&C,&N);
	for(int a=1; a<=A; a+=1)
		for(int b=1; b<=B; b+=1)
			for(int c=1; c<=C; c+=1)
				len[a][b][c]=1;
	for(int i=0;i<N;i+=1){
		scanf("%d %d %d",&x,&y,&z);
		len[x][y][z]=0;
	}
	// dp
	for(int a=1; a<=A; a+=1)
		for(int b=1; b<=B; b+=1)
			for(int c=1; c<=C; c+=1){
				if(len[a][b][c]==1)
					len[a][b][c]=min_len(a,b,c)+1;
				cnt[a][b][c]=len[a][b][c]+cnt[a-1][ b ][ c ]+cnt[ a ][b-1][ c ]+cnt[ a ][ b ][c-1]
				                         -cnt[a-1][b-1][ c ]-cnt[a-1][ b ][c-1]-cnt[ a ][b-1][c-1]
										 +cnt[a-1][b-1][c-1];
			}
	printf("%d\n",cnt[A][B][C]);
}

