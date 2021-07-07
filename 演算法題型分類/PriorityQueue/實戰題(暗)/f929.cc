/* 給定Ｎ格的初始值和Ｑ次操作，輸出查詢時陣列中第一個０的位置？
 * 1 x : 將陣列中第一個值是０位置的數值設定為 x
 * 2 x : 將陣列中第 x 個位置的數值設定為０
 * 3   : 輸出陣列中第一個值是０的位置
 * 解題關鍵：MinHeap + LazyUpdate(惰性更新)
 * 維護陣列中數值是０的位置(儲存時為負數，利用 MaxHeap 輸出最小的數字)
 * LazyUpdate : 因為 PriorityQueue 無法支援刪除容器內任意的數字，所以需要確認移除的數字(位置)是０
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxQ=1e5;
int num[MaxN];
int main(){
	int N, Q, opt ,x;
	priority_queue<int> PQ; 
	
	scanf("%d",&N);
	for(int i=0; i<N; i+=1){
		scanf("%d",&num[i]);
		if(num[i]==0)
			PQ.push(-i);
	}
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%d",&opt);
		switch(opt){
			case 1:
				scanf("%d",&x);
				while(PQ.empty()==0 and num[-PQ.top()]!=0)
					PQ.pop();
				if(PQ.empty()==0 and x!=0){
					num[ -PQ.top() ]=x;
					PQ.pop();
				}
				break;
			case 2:
				scanf("%d",&x);
				if(num[x]!=0){
					num[x]=0;
					PQ.push(-x);
				}
				break;
			default:
				while(PQ.empty()==0 and num[-PQ.top()]!=0)
					PQ.pop();
				printf("%d\n",(PQ.empty()==0)? -PQ.top(): -1);
		}
	}
}