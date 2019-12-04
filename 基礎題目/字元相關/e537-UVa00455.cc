/* 輸出最短的循環子字串
 * 子字串的長度必定是原字串長度的因數, 因為原字串長度 ≤ 80, 可以暴力法測試( 迴圈從1開始枚舉可能的長度 )
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxLen=80;
char ss[MaxLen+2];
int main(){
	int caseT;
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%s",ss);
		int subL, L=strlen(ss);
		for( subL=1; subL<L; subL++)
			if(L%subL==0){
				bool Same=1;
				for(int j,i=0; Same and i<subL; i++){
					for(j=1;j<(L/subL) and ss[j*subL+i]==ss[i]; j++);
					Same=j==(L/subL);
				}
				if(Same) break;
			}
		printf("%d\n",subL);
	}
}