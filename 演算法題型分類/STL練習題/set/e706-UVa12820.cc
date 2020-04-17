/* 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e4;
const int MaxL=30+2;
char ss[MaxL];
int main(){
	for(int caseI=1,caseT;scanf("%d\n",&caseT)!=EOF;caseI++){
		int AC=0;
		while(caseT--){
			scanf("%s\n",ss);
			vector<int> cnt(26);
			for(int i=0;ss[i]!='\0';i++)
				cnt[ss[i]-'a']++;
			bool IsAC=1;
			int WordCnt=0;
			set<int> memo;
			for(int i=0;i<=25;i++)
				if(cnt[i]){
					WordCnt++;
					if(memo.find(cnt[i])==memo.end()) 
						memo.insert(cnt[i]);
					else{
						IsAC=0; break;
					}
				}
			AC+=IsAC and WordCnt>=2;
		}
		printf("Case %d: %d\n",caseI,AC);
	}
	
}
