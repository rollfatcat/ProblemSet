/* 『區堅查詢』『單點更新』的線段樹
 * 建樹時只有遞迴到葉節點時才讀取輸入並逐步建點，並紀錄該數據的葉節點編號
 * 單點更新時只要找到對應的葉節點往上更新即可。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxK=1e5;
int N, K, qL, qR;
int mul[3*MaxN]; // -100 ≤Ｘi ≤ 100
int leaf[MaxN];
char opt[3], ans[3]={'-','0','+'};
inline int scale(int x){ return (x==0)? 0:(x<0)? -1: 1; }
inline void Build(int nL,int nR,int idx){
	if(nL==nR){ 
		scanf("%d",&mul[idx]); 
		mul[idx]=scale(mul[idx]);
		leaf[nL]=idx;
		return;
	}
	int nM=nL+nR>>1;
	Build(  nL,nM,  idx<<1);
	Build(nM+1,nR,idx<<1|1);
	mul[idx]=mul[idx<<1]*mul[idx<<1|1];
}
inline int Query(int nL,int nR,int idx){
	if(qL<=nL and nR<=qR){ return mul[idx]; } 
	int nM=nL+nR>>1, out=1;
	if(nM>=qL)out*=Query(  nL,nM,  idx<<1);
	if(nM<qR )out*=Query(nM+1,nR,idx<<1|1);
	return out;
}
int main(){
	while(scanf("%d %d\n",&N,&K)==2){
		Build(1,N,1);
		while(K--){
			scanf("%s %d %d\n",opt,&qL,&qR);
			if(opt[0]=='C'){ // 單點修改
				mul[leaf[qL]]=scale(qR);
				for(int idx=leaf[qL]>>1;idx;idx>>=1)
					mul[idx]=mul[idx<<1]*mul[idx<<1|1];
			}else{ //區間查詢
				putchar(ans[Query(1,N,1)+1]);
			}
		}
		putchar('\n');
	}
}