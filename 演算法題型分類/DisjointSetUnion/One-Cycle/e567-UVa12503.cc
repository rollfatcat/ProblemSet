/* 當執行『相同於命令i』時類似 DisjointSet 的函數：FindRoot()
 * (1)路徑壓平的概念：直接紀錄Root的命令
 * (2)不需要存命令的字串, 只需要紀錄該命令的位移。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=100;
const int MaxN=100;
int mv[MaxN+1];
int main(){
	int caseT, N, x;
	char cmd[10];
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%d\n",&N);
		int now=0;
		for(int i=1;i<=N;i++){
			scanf("%s",cmd);
			if(cmd[0]=='S'){ // cmd=="SAME"
				scanf("%s %d",cmd,&x);
				mv[i]=mv[x];
			}else
				mv[i]=(cmd[0]=='L')? -1: 1;
			now+=mv[i];	
		}
		printf("%d\n",now);
	}
}