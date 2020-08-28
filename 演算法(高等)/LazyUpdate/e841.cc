/* 給定Ｎ個編號１到Ｎ的寶箱和Ｍ個操作，輸出最後裝著最多硬幣的寶箱編號和該寶箱裝有的錢幣數量？
 * 操作：ＰＱＲＳ
 * Ｒ＝１，從Ｐ到Ｑ區間內的寶箱增加Ｓ枚金幣
 * Ｒ＝２，從Ｐ到Ｑ區間內的寶箱金幣增加Ｓ倍，此操作的增量同樣對之後增加的金幣一樣有效。
 * 解題關鍵：ＲＭＱ(延遲標記)，弱化版的 LazyUpdate ( 只需要處理 PushDown 而可以不考慮 PushUp )
 * Ｎ和Ｍ都極大，所以區間更新的時間必須達到Ｏ(㏒Ｎ)
 * 因為操作２的倍增效果，需要將乘法和加法的區域資訊分開處理。
 * 最後輸出最大值時從頭開始更新整個 SegmentTree 的 LazyTag直到葉節點，並依序比對葉節點的乘績。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxM=1e6;
int addv[MaxN<<2];
int mulv[MaxN<<2];
int qL, qR, qV, type, ansID, ansv;

void NewTree(int nL,int nR,int idx){
	addv[idx]=0; mulv[idx]=1;
	if(nL==nR) return;
	int nM=nL+nR>>1;
	NewTree(  nL,nM,  idx<<1);
	NewTree(nM+1,nR,idx<<1|1);
}

void ModifyADD(int nL,int nR,int idx){
	/* PushDown */
	if(nL<nR and addv[idx]>0)
		addv[ idx<<1 ]+=addv[idx],
		addv[idx<<1|1]+=addv[idx],
		addv[idx]=0;
	if(qL<=nL and nR<=qR){ addv[idx]+=qV; return; }
	int nM=nL+nR>>1;
	if(qL<=nM) ModifyADD(  nL,nM,  idx<<1);
	if(nM< qR) ModifyADD(nM+1,nR,idx<<1|1);
}
void ModifyMUL(int nL,int nR,int idx){
	/* PushDown */
	if(nL<nR and mulv[idx]>1)
		mulv[ idx<<1 ]*=mulv[idx],
		mulv[idx<<1|1]*=mulv[idx],
		mulv[idx]=1;
	if(qL<=nL and nR<=qR){ mulv[idx]*=qV; return; }
	int nM=nL+nR>>1;
	if(qL<=nM) ModifyMUL(  nL,nM,  idx<<1);
	if(nM< qR) ModifyMUL(nM+1,nR,idx<<1|1);
}
void Query(int nL,int nR,int idx){
	/* PushDown */
	if(nL<nR)
		addv[ idx<<1 ]+=addv[idx],
		addv[idx<<1|1]+=addv[idx],
		mulv[ idx<<1 ]*=mulv[idx],
		mulv[idx<<1|1]*=mulv[idx];
	if(nL==nR){
		int thsv=addv[idx]*mulv[idx];
		if(thsv>ansv)
			ansID=nL, ansv=thsv;
		return; 
	}
	int nM=nL+nR>>1;
	Query(  nL,nM,  idx<<1);
	Query(nM+1,nR,idx<<1|1);
}

int main(){
	int N, M;
	scanf("%d %d\n",&N,&M);
	NewTree(1,N,1);
	while(M-->0){
		scanf("%d %d %d %d",&qL,&qR,&type,&qV);
		(type==1)? ModifyADD(1,N,1): ModifyMUL(1,N,1);
	}
	ansv=ansID=0;
	Query(1,N,1);
	printf("%d %d\n",ansID,ansv);
}
