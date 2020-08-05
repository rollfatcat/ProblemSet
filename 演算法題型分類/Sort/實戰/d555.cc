#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
int data[MaxN][2];
int ord[MaxN];
int ans[MaxN];

bool compare(int a,int b){ return (data[a][0]==data[b][0])? data[a][1]<data[b][1]: data[a][0]<data[b][0]; }
int main(){
	int N;
	for(int caseI=1;scanf("%d\n",&N)!=EOF;caseI++){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&data[i][0],&data[i][1]);
		for(int i=0;i<N;i++)
			ord[i]=i;
		sort(ord,ord+N,compare);
		
		int ansL=0;
		int now_y=data[ ord[N-1] ][1];
		ans[ansL++]=ord[N-1];
		for(int i=N-2;i>=0;i--)
			if(data[ ord[i] ][1]>now_y)
				ans[ansL++]=ord[i],
				now_y=data[ ord[i] ][1];
				
		printf("Case %d:\nDominate Point: %d\n",caseI,ansL);
		for(int i=ansL-1;i>=0;i--)
			printf("(%d,%d)\n",data[ans[i]][0],data[ans[i]][1]);
	}
}
