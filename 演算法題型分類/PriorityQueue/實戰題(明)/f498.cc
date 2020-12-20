/* 給定Ｎ個整數，模擬 MaxHeap 和 MinHeap 的插入方式後輸出 HeapSort 的結果。
 * 解題關鍵：堆疊排序
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=(1<<10)+1;
class MinHeap{
	public:
		int N, num[MaxN];
		MinHeap(int N=0):N(N){};
		void HeapInsert(int x){
			num[++N]=x;
			for(int p=N; p>1 and num[p]<num[p>>1]; p>>=1)
				swap(num[p],num[p>>1]);
		}
		void HeapShow(){
			for(int i=1;i<=N;i++)
				printf("%d ",num[i]);
			putchar('\n');
		}
};
class MaxHeap{
	private:
	public:
		int N, num[MaxN];
		MaxHeap(int N=0):N(N){};
		void HeapInsert(int x){
			num[++N]=x;
			for(int p=N; p>1 and num[p]>num[p>>1]; p>>=1)
				swap(num[p],num[p>>1]);
		}
		void HeapShow(){
			for(int i=1;i<=N;i++)
				printf("%d ",num[i]);
			putchar('\n');
		}
};
int main(){
	int N, x;
	MinHeap minHeap=MinHeap();
	MaxHeap maxHeap=MaxHeap();
	while(scanf("%d\n",&N)!=EOF){
		minHeap.N=maxHeap.N=0;
		while(N-->0){
			scanf("%d",&x);
			minHeap.HeapInsert(x);
			maxHeap.HeapInsert(x);
		}
		minHeap.HeapShow();
		maxHeap.HeapShow();
	}
}