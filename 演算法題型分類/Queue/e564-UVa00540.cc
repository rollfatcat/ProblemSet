/* 模擬排隊(支援插隊)
 * 插隊：Queue 中每個元素都屬於某個 team。檢查他的 teammates(同一team的元素)是否已經在 Queue 中。
 * 如果是，它將排在他的 team 的最後一個。如果不是，它將排在Queue最後面。
 * 解題關鍵：Queue In Queue
 * mainQ : 維護加入 Queue 中的 teamQ (佇列編號)的順序
 * teamQ : 維護加入 Queue 中的 element
 * DEQUEUE = 移除 mainQ.front() 的佇列編號中最前面的 element，注意移除後 teamQ 空掉時也得一並從 mainQ 移除
 * ENQUEUE = 加入這個 element 所屬的 teamQ 中，如果這個 teamQ 不存在 mainQ 時則把這個 teamQ 加入 mainQ 尾端
 * 		輸入的 element 需要對映到他所屬的 teamQ ... map
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3; // N fot #Team
const int MaxM=1e3; // M for #member
const int MaxX=1e6; // 0 ≤ xi ≤ 999999

int memo[MaxX];
bool InQ[MaxN+1];
deque<int> teamQ[MaxN+1];
int main(){
	int N, teamsz, member;
	char ss[10];
	for(int caseI=1; scanf("%d",&N) and N>0; caseI++){	
		fill( InQ+1, InQ+1+N,0);
		// input
		teamQ[0].clear();
		for(int tID=1; tID<=N; tID+=1){
			scanf("%d",&teamsz);
			while(teamsz-->0){
				scanf("%d",&member);
				memo[member]=tID;
			}
			teamQ[tID].clear();
		}
		// 模擬 Queue in Queue
		printf("Scenario #%d\n",caseI);
		while(scanf("%s",ss) and ss[0]!='S'){
			// ENQUEUE
			if(ss[0]=='E'){ 
				scanf("%d",&member);
				int tID=memo[member];
				if(InQ[tID]==0){
					teamQ[0].push_back(tID);
					InQ[tID]=1;
				}
				teamQ[tID].push_back(member);
			}else{ // DEQUEUE
				int tID=teamQ[0].front();
				printf("%d\n",teamQ[tID].front());
				teamQ[tID].pop_front();
				if(teamQ[tID].empty()){
					teamQ[0].pop_front();
					InQ[tID]=0;
				}
			}
		}
		putchar('\n');
	}
}