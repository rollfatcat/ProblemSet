/* 模擬排隊(支援插隊)但存在不屬於隊伍的單獨號碼。
 * 插隊：Queue 中每個元素都屬於某個 team。檢查他的 teammates(同一Team的元素)是否已經在 Queue 中。
 * 如果是，它將排在其Team的最後一個。如果不是，它將排在Queue最後面。
 * 解題關鍵：LazyUpdate + Queue In Queue
 * MainQ : 維護加入 Queue 中的 teamQ (佇列編號)的順序，單獨號碼為負的
 * TeamQ : 維護加入 Queue 中的 element
 * Dequeue = 移除 mainQ.front() 的佇列編號中最前面的 element，注意移除後 teamQ 空掉時也得一並從 mainQ 移除
 * Enqueue = 加入這個 element 所屬的 teamQ 中，如果這個 teamQ 不存在 mainQ 時則把這個 teamQ 加入 mainQ 尾端
 * 		輸入的 element 屬於"單獨"(不屬於隊伍)時 mainQ 內儲存的號碼為負數(隊伍號碼範圍１:Ｎ，避開０)
 * 		輸入的 element 需要對映到他所屬的 teamQ ( 0 ≤ xi ≤ 999999 )
 * LazyUpdate 紀錄某個號碼是否對應的 caseID 和當下處理的 case 相同 ... 判斷號碼是否屬於"單獨"
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxV=1e7; // 0 ≤ xi ≤ 999999
const int MaxN=1e3;
const int MaxQ=2e5;

char opt[10];
int team[MaxV];
int csID[MaxV]={};

int main(){
	int teamSz, cnt, mem, tID;
	for(int cID=1; scanf("%d",&teamSz)!=EOF; cID+=1){
		printf("Line #%d\n",cID);
		// input
		for(tID=1; tID<=teamSz; tID+=1)
			for(scanf("%d",&cnt); cnt>0; cnt-=1){
				scanf("%d",&mem);
				team[mem]=tID;
				csID[mem]=cID;
			}
		// query
		queue<int> teamQ;
		queue<int> memQ[teamSz+1];
		while(scanf("%s",opt) and opt[0]!='S'){
			switch(opt[0]){
				case 'E':
					scanf("%d",&mem);
					if(csID[mem]<cID){
						teamQ.push( -mem );
					}else{
						tID=team[mem];
						if( memQ[tID].empty() )
							teamQ.push( tID );
						memQ[tID].push(mem);
					}
					break;
				case 'D':
					if(teamQ.front()<=0){
						printf("%d\n",-teamQ.front());
						teamQ.pop();
					}else{
						tID=teamQ.front();
						printf("%d\n",memQ[tID].front());
						memQ[tID].pop();
						if(memQ[tID].empty())
							teamQ.pop();
					}
			}
		}
	}
}