#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=5;
const int MaxN=1e5;
int ord[MaxN];
int hgt[MaxN];
int bound[MaxN];
 
bool compare(int a,int b){ return bound[a]<bound[b]; }
int main(){
	int caseT, N;
 
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N);
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&hgt[i],&bound[i]), 
            ord[i]=i;
		/* 順序性更新：根據起點限制小到大 */
        sort(ord,ord+N,compare);

        /* Moore-Hodgeson演算法
		 * 貪婪法：同樣數量的動物高度總和越低越好，需要維護目前紀錄的所有動物高度。
		 * 當 起點限制 ≥ 目前高度總和 時直接將這隻動物加入數據結構中，數量+1。
		 * 當 起點限制 < 目前高度總和 時考慮是否置換數據結構當中佔有高度最大的動物，此時因為置換總數量不變。
         * 數據結構需要支援：(1)查詢最大值 和 (2)加入新值後，維護數據結構的性質不變
         */
		int ans=0;
		int tot=0;
		priority_queue<int> start;
		for(int i=0;i<N;i++){
			int pvt=ord[i];
			if( bound[pvt]>=tot ){
				tot+= hgt[pvt];
        		start.push(hgt[pvt]);
				ans++;
			}else{ // bound[pvt]<tot 決定是否置換
				if( hgt[pvt]<start.top() ){
          			tot-=start.top();
        			start.pop();
        			tot+=hgt[pvt];
        			start.push(hgt[pvt]);
        		}
			}
		}
		printf("%d\n",ans);
	}
}