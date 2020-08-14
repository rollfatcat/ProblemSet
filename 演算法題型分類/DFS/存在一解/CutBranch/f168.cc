#include<bits/stdc++.h>
using namespace std;

const int MaxN=16;
const int MaxV=1e7;
int N, sumv, avg; 
int item[MaxN];

bool compare(int a,int b){ return a>b; }
bool DFS(int a,int b,int c,int idx){
	/* 剩餘一件物品時，最大剩餘價值必須符合該物品的價值 */
    if(idx==N-1) return a==item[idx];
	/**/
    if(item[idx]>a) return false;
	if(a-item[idx]<c){ 
		if(DFS(b,c,a-item[idx],idx+1)) 
			return true; 
	}else if(a-item[idx]<b){ 
		if(DFS(b,a-item[idx],c,idx+1)) 
			return true; 
	}else{
		if(DFS(a-item[idx],b,c,idx+1)) 
			return true;
	}
	
	if(b>=item[idx]){
		if(b-item[idx]< c and DFS(a,c,b-item[idx],idx+1)) return true;
		if(b-item[idx]>=c and DFS(a,b-item[idx],c,idx+1)) return true;
	}
	if(c>=item[idx] and DFS(a,b,c-item[idx],idx+1)) return true;
	
	return false;
}
int main(){
	while(scanf("%d\n",&N)!=EOF){
		sumv=0;
		for(int i=0;i<N;i++)
			scanf("%d",&item[i]), 
			sumv+=item[i];
		avg=sumv/3;
		sort(item,item+N,compare);
		if(sumv%3 or item[0]>avg){ puts("NO"); continue; }
		(DFS(avg,avg,avg-item[0],1))? puts("YES"): puts("NO");
	}
}