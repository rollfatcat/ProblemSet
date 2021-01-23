/* Ｎ位同學身上的費用和Ｍ道菜的價格，依照規則付費後輸出開始時和結束後錢最多的同學身上的費用？費用不足時輸出"Oh My God"
 * 規則：每次都由目前身上錢最多的同學付錢，費用不足時則由錢次多的付費，不夠時則由第三多的...依此類推
 * 解題關鍵：PriorityQueue
 * 維護目前錢最多的同學並模擬支付費用的流程，持續由 PQ.top() 負擔。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;
const int MaxN=1e4;

int main(){
	int N, M, v;
	while(scanf("%d %d\n",&N,&M)!=EOF){
		priority_queue<int> PQ;
		while(N-->0){
			scanf("%d",&v);
			PQ.push(v);
		}
		int max_v=PQ.top();
		while(M-->0){
			scanf("%d",&v);
			while(PQ.empty()==0 and v>0){
				if(v<PQ.top())
					PQ.push(PQ.top()-v);
				v-=PQ.top();
				PQ.pop();
			}
		}
		(PQ.empty() and v>0)? puts("Oh My God"): printf("%d %d\n",max_v,(PQ.empty())? 0: PQ.top());
	}
}