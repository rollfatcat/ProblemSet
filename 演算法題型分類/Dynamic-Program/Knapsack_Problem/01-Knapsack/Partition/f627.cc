/* 給定Ｎ種礦石和背包負重上限Ｍ，每一種礦石會給予開採的能選取的最大量和單位價值，輸出背包能帶走的最大價值？
 * 解題關鍵：排序( Greedy )
 * 從單位價值最高的開始挑選直到背包裝滿
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
const int MaxM=1e5;
const int MaxW=1e2;
const int MaxP=1e3;
 
struct ITEM{
	int w, p;
	bool operator<(const ITEM &rhs)const{ return p>rhs.p; }
} item[MaxN];
 
int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d %d\n",&item[i].w,&item[i].p);
	sort(item,item+N);
 
	int sum_v=0, max_w;
	for(int i=0;i<N and M>0;i++){
		max_w=min(M,item[i].w);
		sum_v+= max_w*item[i].p;
		M-=max_w;
	}
	printf("%d\n",sum_v);
}