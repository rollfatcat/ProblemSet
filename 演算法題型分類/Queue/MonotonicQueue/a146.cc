/* 給定Ｎ個數字和區間長度Ｋ，輸出每個區間內的最大/最小值？
 * 題目盲點：題目沒有保證 K ≤ N
 * 解題關鍵：sliding window(size＝Ｋ... 連續Ｋ個)
 * 		monotonic queue(單調佇列) ... 0.5s
 * 		multiset                 ... 1.8s
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
long num[MaxN+1];
deque<int> maxQ;
deque<int> minQ;
vector<int> ans;
int main(){
	int N, K;
	
	while(scanf("%d %d",&N,&K)!=EOF){
        K=min(K,N); // 題目沒有保證 K ≤ N
		
		maxQ.clear();
		minQ.clear();
		ans.clear();
		for(int i=1; i<=N; i+=1){
			scanf("%ld",&num[i]);
			while(maxQ.empty()==0 and num[maxQ.back()]<=num[i])
				maxQ.pop_back();
			maxQ.push_back(i);
			if(i-maxQ.front()==K)
				maxQ.pop_front();
			
			while(minQ.empty()==0 and num[minQ.back()]>=num[i])
				minQ.pop_back();
			minQ.push_back(i);
			if(i-minQ.front()==K)
				minQ.pop_front();
				
			if(i>=K){
				printf("%ld",num[minQ.front()]);
				putchar((i==N)? '\n': ' ');
				ans.push_back(maxQ.front());
			}
		}
		
		printf("%ld",num[ans[0]]);
		for(int i=1; i<ans.size();i+=1)
			printf(" %ld",num[ans[i]]);
		putchar('\n');
	}
}