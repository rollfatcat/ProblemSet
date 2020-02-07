/* 在滿足每個Row/Col的最少燈泡點亮的要求下, 最少化點亮的#燈泡
 * 最少化需要點亮的#燈泡＝最大化交叉的#點
 * 貪婪法，枚舉每個Row，優先在『需要點亮的剩餘燈泡中最多』的column點亮該位置的燈泡，但每一個column在這個row只能被點亮一次。
 * 需要點亮的剩餘燈泡中最多：Heap維護, 並確保Heap內有數字時才能夠產生『交叉的點』
 * 每一個column在這個row只能被點亮一次：暫存到Queue,再一次推入
 * 除了每次Row有沒有剩下，最後要檢查Heap內是不是有多出來的
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;
const int MaxN=1000;
const int MaxM=1000;

int main(){
	int caseT, N, M, num;
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%d %d\n",&M,&N);
		priority_queue<int,vector<int>> PQ;
		for(int i=0;i<M;i++){
			scanf("%d",&num);
			if(num) 
				PQ.push(num);
		}
		int cnt=0;
		for(int i=0;i<N;i++){
			queue<int> Q;
			for(scanf("%d",&num);num>0 and PQ.empty()==0;num--,cnt++){
				int ths=PQ.top()-1; PQ.pop();
				if(ths) Q.push(ths);
			}
			for(cnt+=num;Q.empty()==0;Q.pop())
				PQ.push(Q.front());
		}
		for(;PQ.empty()==0;PQ.pop())
			cnt+=PQ.top();
		printf("%d\n",cnt);
	}
}