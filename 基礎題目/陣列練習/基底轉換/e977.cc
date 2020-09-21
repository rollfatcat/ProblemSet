/* 給定DNA序列字串，輸出長度和該長度時的字典序編號(從０開始算)
 * 解題關鍵：進位制
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=1e2;
const int MaxL=30;
char ss[MaxL+2];
 
int main(){
	int caseT;
	long v;
 
	int order[128];
	order['A']=0;
	order['C']=1;
	order['G']=2;
	order['T']=3;
 
	scanf("%d\n",&caseT);
	for(int caseI=1;caseT-->0;caseI++){
		scanf("%s\n",ss);
		v=0;
		for(int i=0;ss[i]!='\0';i++)
			v=(v<<2)+order[ss[i]];
		printf("Case %d: (%d:%ld)\n",caseI,strlen(ss),v);
	}
}