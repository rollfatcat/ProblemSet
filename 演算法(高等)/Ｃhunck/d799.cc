/* 給定Ｎ個數字和Ｑ次的操作，當每次操作是查詢區間的數字和時輸出對應的答案？
 * (１,Ｌ,Ｒ,Ｋ): 區間[Ｌ,Ｒ]都增加Ｋ( Ｋ ≦ 1000 )
 * (２,Ｌ,Ｒ): 輸出區間[Ｌ,Ｒ]之間數字的總和
 * 解題關鍵：RangeQuery -  分塊法
 * 更新時，若是有經過『區塊』除了更新區塊的總和還要紀錄『這個區塊被加了多少』，
 *       目的是當之後查詢的範圍無法涵蓋整個區塊時而加總『單點』時額外加上紀錄值
 * 
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=5e5;
const int MaxQ=5e5;
/* ChunkSize : sqrt(MaxN)=707 */
const int MaxChunk_size=710;
/* 區塊內數字的總和 */
long sum[MaxChunk_size]={};
/* 區塊的增加量，為了處理查詢時落在區間內的單點 */
long add[MaxChunk_size]={};
int num[MaxN+1];
 
long ChunkQuery(int qL,int qR,int Csz,long out=0){
	int LID=qL/Csz;
	int RID=qR/Csz;
	if(LID==RID){
		for(int i=qL;i<=qR;i++)
			out+= add[LID]+num[i];
	}else{
		for(int i=qL;i<(LID+1)*Csz;i++)
			out+= add[LID]+num[i];
		for(int i=LID+1;i<RID;i++)
			out+= sum[i];
		for(int i=RID*Csz;i<=qR;i++)
			out+= add[RID]+num[i];
	}
	return out;
}
void ChunkUpdate(int qL,int qR,int qV,int Csz){
	int LID=qL/Csz;
	int RID=qR/Csz;
	if(LID==RID){
		for(int i=qL;i<=qR;i++)
			num[i]+= qV;
		sum[LID]+= qV*(qR-qL+1);
	}else{
		for(int i=qL;i<(LID+1)*Csz;i++)
			num[i]+= qV;
		sum[LID]+= qV*((LID+1)*Csz-qL);
		for(int i=LID+1;i<RID;i++)
			add[i]+= qV, sum[i]+=qV*Csz;
		sum[RID]+= qV*(qR-RID*Csz+1);
		for(int i=RID*Csz;i<=qR;i++)
			num[i]+= qV;
	}
}
int main(){
	int N, Q, opt, qL, qR, qV;
 
	scanf("%d\n",&N); 
	int Csz=sqrt(N);
	int CID=0, Ci=0;
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
		sum[CID]+=num[i];
		CID+= Ci==Csz-1;
		Ci=(Ci==Csz-1)? 0: Ci+1;
	}
	scanf("%d\n",&Q);
	while(Q-->0){
		scanf("%d %d %d",&opt,&qL,&qR);
		if(opt==2)
			printf("%ld\n",SumChunkQuery(qL-1,qR-1,Csz)) ;
		else
			scanf("%d",&qV),
			ChunkUpdate(qL-1,qR-1,qV,Csz);
	}
}