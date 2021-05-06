/* 頻道每天上傳的影片(Vi)但之前上傳的的每部影片會衰退熱門指數(Di)不低於０，輸出該頻道每天的熱門程度？
 * 解題關鍵：優先佇列
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=4e5;
const int MaxV=1e9;
int main(){
	int N, V, D;
 
	while(scanf("%d",&N)!=EOF){
		priority_queue<long,vector<long>,greater<long>> PQ; // MinHeap
		long base=0;
		long sumv=0;
		while(N-->0){
			scanf("%d %d",&V,&D);
			for(base+=D; PQ.empty()==0 and PQ.top()<=base; PQ.pop())
				sumv-= PQ.top();
			PQ.push(base+V);
			sumv+= base+V;
			printf("%ld\n",sumv-PQ.size()*base);
		}
	}
 
}