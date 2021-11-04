#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
int nxt[MaxN];
int food[MaxN];
int main(){
	int N, S;
	
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i+=1)
		scanf("%d",&nxt[i]);
	for(int i=0;i<N;i+=1)
		scanf("%d",&food[i]);
	int ans=0;
	for(; food[S]!=-1; S=nxt[S]){
		ans+=food[S];
		food[S]=-1;
	}
	printf("%d\n",ans);
}

