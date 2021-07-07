/* 給定Ｎ個數字，過程中數字１-Ｎ都會出現且只會出現一次(不重複)，每次輸入新數字時輸出這個數字是第幾大？ 
 * 解題關鍵 : RangeQuery - 分塊法
 * 問題轉換 : 目前輸入的數字 Ｑx 是第幾大＝查詢(０,Ｑx-1 )範圍內的個數
 *           查詢完後更新這個數字 Ｑx 的個數為１以及他的區間編號個數+1
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxCaseT=20;
const int MaxN=1e5;
const int MaxChunk_size=320; // sqrt(MaxN)=316
 
int chunk[MaxChunk_size];
bool num[MaxN+1];
 
inline int ChunkQuery(int v,int Csz,int out=0){
	for(int i=0; i<v/Csz; i++)
		out+=chunk[i];
	for(int i=v/Csz*Csz; i<v; i++)
		out+=num[i];
	return out;
}
inline void ChunkUpdate(int v,int Csz){ num[v]=1; chunk[v/Csz]+=1; }
 
 
int main(){
	int N, v, Csz;
	while(scanf("%d\n",&N)!=EOF){
		Csz=sqrt(N);
		fill(chunk,chunk+MaxChunk_size,0);
		fill(num,num+N,0);
 
		for(int n=1;n<=N;n++){
			scanf("%d\n",&v);
			printf("%d\n",n-ChunkQuery(v-1,Csz));
			ChunkUpdate(v-1, Csz);
		}
	}
}