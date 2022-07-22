/* 給定一個環狀架構的字串(只會由'a'和'b'組成)，選取２點作為切點形成２個字串，符合「要求」的所有切法？
 * 切點：(1,2)代表字串包含陣列位置從1開始一直到2(不包含2這個位置)所構成的子字串
 * 要求：字串Ａ的數量＝另個字串Ｂ的數量 或是 字串Ｂ的數量＝另個字串Ａ的數量
 * 解題關鍵：前綴和＋暴力法(枚舉每組的起點、終點) (66ms)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=200;
const int MaxL=1e3;
 
char ss[MaxL+2];
int prS[MaxL<<1|1]={}; // 紀錄Ｂ個數的前綴和
int main(){
	for(int caseI=1;scanf("%s\n",ss)!=EOF;caseI++){
		int L=strlen(ss);
		int sumB=0;
		for(int i=1; ss[i-1]!='\0'; i++)
			prS[L+i]=prS[i]= ss[i-1]=='b',
			sumB+= ss[i-1]=='b';
		int sumA=L-sumB;
 
		for(int i=1; i<=(L<<1); i++)
			prS[i]+=prS[i-1];
 
		printf("AB Circle #%d:\n",caseI);
		for(int st=0; st<L; st++)
			for(int ed=st+1; ed<L; ed++)
				if(prS[ed]-prS[st] == sumA-(ed-st-(prS[ed]-prS[st])) or
				   ed-st-(prS[ed]-prS[st]) == sumB-(prS[ed]-prS[st]) )
					printf("%d,%d\n",st,ed);
	}
}