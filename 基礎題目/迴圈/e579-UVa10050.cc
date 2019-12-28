/* 給定Ｐ個黨團的罷會週期並保證 Fri. Sat. 不會發生罷會, 模擬不需要開會的日子數
 * 初始的日期是 Sun. 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3650;
const int MaxP=100;
bool off[MaxN];

int main(){
	int caseT, N, P;
	scanf("%d\n",&caseT);
	while(caseT--){
		scanf("%d\n%d\n",&N,&P);
		fill(off,off+N,0);
		int cnt=0;
		for(int x,i=0;i<P;i++){
			scanf("%d\n",&x);
			for(int j=x-1;j<N;j+=x)
				if(j%7<5 and off[j]==0)
					off[j]=1,cnt++;
		}
		printf("%d\n",cnt);
	}
}