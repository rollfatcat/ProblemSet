#include<bits/stdc++.h>
using namespace std;

int N, bag[10];
void DFS(int depth,int status){
	if(depth==N){
		for(int i=0;i<N;i++)
			printf("%d ",bag[i]);
		putchar('\n');
		return;
	}
	for(int pos, nowS=status; nowS>0; nowS^=1<<pos)
		pos=__lg(nowS&-nowS),
		bag[depth]=pos+1,
		DFS(depth+1,status^1<<pos);
}
int main() {
	scanf("%d",&N);
	DFS(0,(1<<N)-1);
}