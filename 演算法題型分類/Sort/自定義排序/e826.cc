#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxM=1e6;
int give[MaxN]={};
int ID[MaxN];
bool compare(int a,int b){
	return (give[a]==give[b])? a<b : give[a]>give[b];
}
int main(){
	int N, M, id, x;
	scanf("%d %d\n",&N,&M);
	for(int i=0;i<N;i++)
		ID[i]=i;
	while(M--)
		scanf("%d %d\n",&id,&x),
		give[id]+=x;
	sort(ID,ID+N,compare);	
	for(int i=0;i<N;i++)
		printf("%d %d\n",ID[i],give[ID[i]]);
}