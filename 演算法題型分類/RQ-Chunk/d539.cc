/* 給定Ｎ個數字和Ｑ次查詢，每次查詢(Ｌ,Ｒ)時輸出區間內的最大值？
 * 解題關鍵 : RangeQuery - 分塊法
 * 額外紀錄大範圍的區間資訊，查詢的區間過大時可以區分成單點和大區塊
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=5e5;
const int MaxQ=5e5;
 
int chunk[710]; // sqrt(MaxN)=707
int num[MaxN+1];
 
int MaxChunkQuery(int qL,int qR,int Csz,int out=INT_MIN){
	int LID=qL/Csz;
	int RID=qR/Csz;
	if(LID==RID){
		for(int i=qL;i<=qR;i++)
			out=max(out,num[i]);
	}else{
		for(int i=qL;i<(LID+1)*Csz;i++)
			out=max(out,num[i]);
		for(int i=LID+1;i<RID;i++)
			out=max(out,chunk[i]);
		for(int i=RID*Csz;i<=qR;i++)
			out=max(out,num[i]);
	}
	return out;
}
int main(){
	int N, Q, Csz, qL, qR;
 
	scanf("%d\n",&N); Csz=sqrt(N);
	fill(chunk,chunk+710,INT_MIN);
 
	int CID=0, Ci=0;
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
		chunk[CID]=max(chunk[CID],num[i]);
		CID+= Ci==Csz-1;
		Ci=(Ci==Csz-1)? 0: Ci+1;
	}
	scanf("%d\n",&Q);
	while(Q-->0){
		scanf("%d %d\n",&qL,&qR);
		if(qL>qR) swap(qL,qR);
		printf("%d\n",MaxChunkQuery(qL-1,qR-1,Csz));
	}
}