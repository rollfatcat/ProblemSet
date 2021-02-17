/* 給定Ｎ個數字且題目保證每個數字不重複(０ ≦ Ｍ ≦ 2^64-1 )，每次輸入新數字時輸出這個數字是第幾大？ 
 * 解題關鍵 : RangeQuery - 分塊法＋離線處理 - 離散化(不需處理重複情況)
 * 數字極大 : 離線處理，將所有查詢的數字儲存後排序，再依照當初輸入順序的數字轉換為 所有數字中的大小。
 * 問題轉換 : 目前輸入的數字，經過上述「離散化」的轉換後 Ｑx 是第幾大＝查詢(０,Ｑx-1 )範圍內的個數
 *           查詢完後更新這個數字 Ｑx 的個數為１以及他的區間編號個數+1
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxChunk_size=320; // sqrt(MaxN)=316

int chunk[MaxChunk_size];
bool one[MaxN];
int  ord[MaxN];
unsigned long org[MaxN];

inline bool compare(int a,int b){ return org[a]<org[b]; }
inline int ChunkQuery(int v,int Csz,int out=0){
	for(int i=0; i<v/Csz; i++)
		out+=chunk[i];
	for(int i=v/Csz*Csz; i<v; i++)
		out+=one[i];
	return out;
}
inline void ChunkUpdate(int v,int Csz){ one[v]=1; chunk[v/Csz]+=1; }

int main(){
	int N, v, Csz;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%lu\n",&org[i]), ord[i]=i;
		/* 離散化：根據原始數字排序後，ord[]儲存的是小到大的編號
		 * 但更新順序需要依照輸入順序，所以反向將小到大的編號覆蓋回原始數據 
		 */
		sort(ord,ord+N,compare);	
		for(int i=0;i<N;i++)
			org[ord[i]]=i;
		
		Csz=sqrt(N);
		fill(chunk,chunk+MaxChunk_size,0);
		fill(one,one+N,0);
		for(int n=1;n<=N;n++)
			printf("%d\n",n-ChunkQuery(org[n-1],Csz)),
			ChunkUpdate(org[n-1],Csz);
	}
}
