/* 一個維度Ｄ的超立方體是由２的Ｎ次方個點組成，每個點均由一個Ｄ-bits的二元數表示，邊連結的兩點條件為代表該點的二進位數只相差一個bit。
 * 依照最短路徑從０移動到(1<<Ｄ)-1 最大化經過路徑可得到的和？
 * 根據"最短路徑的移動方式"可以知道經過路徑的點是遞增的＝由小到大更新。
 * 邊存在的條件＋數字小的一定更新過的特性＝能夠抵達現在的點的狀態必定是依次和一個是１的位數做XOR後的數字。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxD=10;
int dpv[1<<MaxD];

int main(){
	int N, D, v;
	while(scanf("%d",&D) and D){
		N=1<<D;
		for(int now=0;now<N;now++){
			dpv[now]=0;
			for(int LastBit,tmpS=now; tmpS>0; tmpS^=LastBit)
				LastBit=tmpS&-tmpS,
				dpv[now]=max(dpv[now],dpv[now^LastBit]);
			scanf("%d",&v);
			dpv[now]+=v;
		}
		printf("%d\n",dpv[N-1]);
	}
}
