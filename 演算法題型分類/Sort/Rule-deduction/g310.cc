/* 給定Ｎ個ＸＹ
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
int num[2][MaxN];
int main(){
	int N;
	
	scanf("%d",&N);
	for(int i=0;i<N;i+=1)
		scanf("%d",&num[0][i]);
	for(int i=0;i<N;i+=1)
		scanf("%d",&num[1][i]);

	int ans=0;
	for(int p0=N-1,p1=N-1; p1>=0; p1-=1){
		while(0<=p0 and num[0][p0]>=num[1][p1])
			p0-=1;
		if(p0==-1) break;
		ans+=1;
		p0-=1;
	}
	printf("%d\n",ans);
}

