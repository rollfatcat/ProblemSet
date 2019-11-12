/* 循環狀態偵測, 保證抵達零元組或是開始循環時所需的迭代步驟不超過 1000 步
 * 利用"set"紀錄『已經發生過的狀態』方便查詢是否重複出現(因為set是由紅黑樹實現)
 * 但因為型態是自定義的 strcut 所以需要定義operator "<"
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxT=1000; // 最多不超過1000步
const int MaxN=15; // TUPLE 最大長度
int caseT, N;
struct TUPLE{
	int num[MaxN]={};
	bool operator <(const TUPLE &rhs)const{ 
		for(int i=0;i<N;i++)
			if(num[i]!=rhs.num[i])
				return num[i]<rhs.num[i];
		return true; 
	}
	bool IsEnd(int i=0){
		for(;i<N and num[i]==0;i++);
		return i<N;
	}
} now, nxt;
 
 
int main(){
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",&now.num[i]);
		int turn=0;
		bool IsLoop=false;
		for(set<TUPLE> rec;turn<MaxT and now.IsEnd();turn++){
			IsLoop|=(rec.find(now)!=rec.end());
			if(IsLoop) break;
			rec.insert(now);
			for(int i=1;i<N;i++)
				nxt.num[i-1]=abs(now.num[i]-now.num[i-1]);
			nxt.num[N-1]=abs(now.num[0]-now.num[N-1]);
			now=nxt;
		}
		(!IsLoop and turn<MaxT)? puts("ZERO"): puts("LOOP");
	}
}