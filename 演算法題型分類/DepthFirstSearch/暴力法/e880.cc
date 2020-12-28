/* 給定Ｍ組『不能相鄰』的字母，輸出字典序最小的答案
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=15;
const int MaxM=50;
int N, M;
bool use[MaxN]={};
bool lnk[MaxN][MaxN]={};
char bag[MaxN];
inline bool DFS(int depth){
	if(depth==N){
		for(int i=0;i<N;i++)
			putchar(bag[i]+'A');
		putchar('\n');
		return true;
	}
	for(int i=0;i<N;i++)
		if(use[i]==0 and lnk[bag[depth-1]][i]==0){
			bag[depth]=i, 
			use[i]=1;
			if(DFS(depth+1)) 
				return true;
			use[i]=0;
		}
	return false;
}
int main(){
	scanf("%d\n%d\n",&N,&M);
	for(char u,v;M--;)
		scanf("%c %c\n",&u,&v),
		lnk[u-'A'][v-'A']=lnk[v-'A'][u-'A']=1;
		
	int i=0;
	for( ;i<N;i++){
		bag[0]=i, 
		use[i]=1;
		if(DFS(1)) break;
		use[i]=0;
	}
	if(i==N)  puts("No Solution");
}