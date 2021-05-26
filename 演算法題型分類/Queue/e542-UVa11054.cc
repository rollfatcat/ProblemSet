/* 兩個指標的移動類似Queue( 可用Queue實作 )
 * 題目問搬動數字讓整個陣列值都歸零的成本, 每單位的搬動成本=搬動一單位移動的格子數
 * 5 -4 1 -3 1
 * 從 idx=0 搬4個單位 到 idx=1: 4
 * 從 idx=0 搬1個單位 到 idx=3: 3
 * 從 idx=2 搬1個單位 到 idx=3: 1
 * 從 idx=4 搬1個單位 到 idx=3: 1
 * 總成本＝4+3+1+1＝9
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int cnt[MaxN]; // -1000 ≤ cnt[i] ≤ 1000

int main(){
	int N;
	while(scanf("%d",&N) and N){
		for(int i=0;i<N;i++)
			scanf("%d",&cnt[i]);
		int sum=0;
		for(int front=0, rear=1;rear<N;rear++){
			if(rear==front or cnt[front]*cnt[rear]>0) 
				continue;
			while(front<rear and abs(cnt[front])<=abs(cnt[rear]))
				sum+=abs(cnt[front])*(rear-front),
				cnt[rear]+=cnt[front], 
				cnt[front++]=0;
			if(front<rear and abs(cnt[rear]))
				sum+=abs(cnt[rear])*(rear-front),
				cnt[front]+=cnt[rear],
				cnt[rear]=0;
		}
		printf("%d\n",sum);
	}
}