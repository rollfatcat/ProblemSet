/* 分層架構的Queue(類似莫隊的分塊概念), e564 的加強版, 存在落單的號碼(無隊伍)
 * 用原本資料結構的佇列即可實現本題的資料結構（以下稱團體佇列）之特性。其中一個佇列，
 * 其排隊的單位為團體；而每個團體自己各自有一個佇列，其排隊單位則是人。
 * 每當要把人加入團體佇列時，先看該人所屬團體有無在團體佇列裡
 * （可以用一個布林值表示團體的有無）。如果有就將該人放到所屬團體裡的佇列；
 * 沒有的話，就將該人的團體放進團體佇列尾端，並將該人放到團體的佇列裡。
 * 當要從團體佇列移出人時，先看團體佇列最前端的團體是何者。
 * 再從該團體的佇列移出該團體最前端的人。如果該團體的佇列已空，則代表該團體的成員都不在團體佇列裡，
 * 所以要從團體佇列中移出。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000;  // N fot #Team
const int MaxM=1000;  // M for #member
const int MaxQ=200000;// Q for #opt
const int MaxNo=1e6;
//map<int,int> memo; // 0 ≤ xi ≤ 999999, 因為 No. ≤ 999999 可以直接利用陣列建立映射表：先確認號碼目前是哪個caseI再對應隊伍
int CaseNo[MaxNo]; // 確認現在這個號碼是在哪個caseI
int TeamNo[MaxNo]; // 確認現在這個號碼是哪個隊伍
queue<int> teamQ;
queue<int> Q[MaxN];
int leader[MaxN];
bool InQ[MaxN];

int main(){
	int N, teamsz, member;
	char ss[10];
	for(int caseI=1;scanf("%d",&N)!=EOF;caseI++){
		printf("Line #%d\n",caseI);
		// initial
		while(teamQ.empty()==0)
			teamQ.pop();
		for(int i=0;i<N;i++)
			while(Q[i].empty()==0)
				Q[i].pop();
		fill(InQ,InQ+N,0);
		// input
		for(int teamID=0;teamID<N;teamID++){
			scanf("%d",&teamsz);
			scanf("%d",&member);
			leader[teamID]=member;
			TeamNo[member]=teamID;
			CaseNo[member]=caseI;
			for(int i=1;i<teamsz;i++){
				scanf("%d",&member);
				TeamNo[member]=teamID;
				CaseNo[member]=caseI;
			}
		}
		// 模擬TeamQueue的行為：Push和Pop
		while(scanf("%s",ss) and ss[0]!='S'){
			if(ss[0]=='E'){
				scanf("%d",&member);
				if(CaseNo[member]!=caseI)
					teamQ.push(member);
				else{
					int team=TeamNo[member];
					if(InQ[team]==0){
						teamQ.push(leader[team]);
						InQ[team]=1;
					}
					Q[team].push(member);
				}
			}else{
				member=teamQ.front();
				if(CaseNo[member]!=caseI){
					printf("%d\n",member);
					teamQ.pop();
				}else{
					int team=TeamNo[member];
					printf("%d\n",Q[team].front());
					Q[team].pop();
					if(Q[team].empty()){
						teamQ.pop();
						InQ[team]=0;
					}
				}
			}
		}
	}
}