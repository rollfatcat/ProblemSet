/* 給定Ｎ個地雷的引爆類型，輸出引爆後的結果？
 * 類型：(1)啞炮＝不觸發其他地雷 (2)左右炮＝波及左右２格地雷 (3)怪怪炮＝波及 i-2k, i-k, i+k, i+2k ４個格子
 * 解題關鍵：BFS(每個位置/狀態只需要展開一次)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e3;
int N, T;
int num[MaxN];
bool InQ[MaxN]={};
bool InRange(int x){ return 0<=x and x<N; }
 
int main(){
 
	scanf("%d",&N);
	for(int i=0;i<N;i+=1)
		scanf("%d",&num[i]);
	scanf("%d",&T);
 
	queue<int> Q;
	InQ[T]=1;
	Q.push(T);
	while(Q.empty()==0){
		int n=Q.front(); Q.pop();
		if(num[n]==2){
			if(InRange(n-1) and InQ[n-1]==0) 
				InQ[n-1]=1, Q.push(n-1);
			if(InRange(n+1) and InQ[n+1]==0) 
				InQ[n+1]=1, Q.push(n+1);
		}
		if(num[n]>=3){
			if(InRange(n-num[n]) and InQ[n-num[n]]==0) 
				InQ[n-num[n]]=1, Q.push(n-num[n]);
			if(InRange(n+num[n]) and InQ[n+num[n]]==0) 
				InQ[n+num[n]]=1, Q.push(n+num[n]);
			if(InRange(n-2*num[n]) and InQ[n-2*num[n]]==0) 
				InQ[n-2*num[n]]=1, Q.push(n-2*num[n]);
			if(InRange(n+2*num[n]) and InQ[n+2*num[n]]==0) 
				InQ[n+2*num[n]]=1, Q.push(n+2*num[n]);
		}
 
	}
	for(int i=0;i<N;i+=1)
		printf("%d ",InQ[i]? 0: num[i]);
}