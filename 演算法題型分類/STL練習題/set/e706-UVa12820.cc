/* 題目給定由小寫字母構成的字串後，判斷該字串出現的字母頻率是否皆不相同。
 * 符合要求的字串除了頻率皆不同外，必須具備"最少"有兩種字母。
 * 統計每個字母後，用 set 紀錄出現的個數檢查是否有重複的
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
