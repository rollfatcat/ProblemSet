// 題目的輸入範圍極大，不可能枚舉任兩個端點找出最長的區間
// (區間內的數不一定都要大於端點，但計算長度時只算大於端點的數字個數)
// 題目的解法相對簡單(要證明作法正確性需要討論兩種整情況：更新點落在現在區間內或是外側)
/* (X)原本以為是由大到小更新個數搭配BIT的計算區間內的個數
 * 演繹法(從第一步推導到第二步)
 * (a) 更新時下個點落在現在區間外面，這時更新端點(左或右)且扣除已經填入的點數
 * (b) 更新時下個點落在現在區間內部，這時兩端點不變但新長度會比上一次紀錄的長度多扣除1
 * 舉例：1 0 0 1 0 0  <- 第一步先抓數字最小的兩個點當作區間並計算初始化的長度
 *       1 0 0 1 0 1  <- 新點落在區間外側
 *       1 0 1 1 0 0  <- 新點落在區間內部
 */
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000

struct NODE{
	int v, o;
	bool operator<(const NODE &rhs)const{ return v<rhs.v; }
} node[MAXN];

int main() {
	int N;
	while(scanf("%d",&N)!=EOF){
		for(int i=0;i<N; i++)
			scanf("%d",&node[i].v),
			node[i].o=i;
		if(N==1){ puts("1"); continue; }

		// 根據數字由小到大依序更新左右邊界
		sort(node,node+N);
		int nL=min(node[0].o,node[1].o);
		int nR=max(node[0].o,node[1].o);
		int maxL=nR-nL+1; // 需要至少兩個端點(所以要先屏除特殊情況：N=1)
		int IsIn=2; //已經有兩個點被填入
		for(int i=2;i<N;i++,IsIn++){
			nL=min(nL,node[i].o);
			nR=max(nR,node[i].o);
			maxL=max(maxL,nR-nL+1-(IsIn-1) ); // IsIn因為有一個點拿去當端點所以要扣除
		}
		printf("%d\n",maxL);
	}
}
// 5 1 9 2 8 6