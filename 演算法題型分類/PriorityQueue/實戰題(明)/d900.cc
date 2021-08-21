/* Ｎ位同學的接水時間和Ｍ個取水區，每位同學依照順序取水，輸出所有同學取完水的時間？
 * 解題關鍵：PriorityQueue
 * 前Ｍ位同學可以在時間０時到取水區，之後的同學需要等到取水區空出來時才能開始取水。
 * PriorityQueue 維護Ｍ個取水區"下次空出來"的時間，將目前同學安排給"最快"空出來的 ... MinHeap
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
const int MaxM=1e2;
const int MaxW=1e2;
 
int main(){
	int N, M, v, p;
 
	while(scanf("%d %d",&N,&M)!=EOF){
		if(M>N) M=N;
 
		vector<int> t(M);
		priority_queue< vector<int> > PQ;
		for(int i=0;i<M;i+=1){
			scanf("%d",&t[i]);
			PQ.push({-t[i],i});
		}
		for(int i=M;i<N;i+=1){
			scanf("%d",&v);
			p=PQ.top()[1]; PQ.pop();
			t[p]+=v;
			PQ.push({-t[p],p});
		}
		while(PQ.size()>1)
			PQ.pop();
		printf("%d\n",-PQ.top()[0]);
	}
}