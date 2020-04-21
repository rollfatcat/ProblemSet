/* 給定班級人數Ｎ和３位缺席的號碼，由大到小輸出出席同學的號碼。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20; // ３<Ｎ≤ 20
int main(){
	for(int N,x;scanf("%d\n",&N)!=EOF;){
		vector<bool> leave(N+1);
		scanf("%d",&x), leave[x]=1;
		scanf("%d",&x), leave[x]=1;
		scanf("%d",&x), leave[x]=1;
		for(int i=N;i>0;i--)
			if(leave[i]==0)
				printf("No. %d\n",i);
	}
}