// RMQ = Range Minimum/Maximum Query
// 為何SegmentTree的空間需求是4N：https://blog.csdn.net/Monster_Day/article/details/52214711
/* 給定Ｎ個數字和Ｑ次查詢範圍 qL: qR，輸出每次查詢範圍內的最大值？
 * 實作：基礎線段樹 - 區間查詢
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
const int MaxQ=5e5;
int qL, qR;
int num[MaxN];
int seg[MaxN<<2];

void BuildTree(int nL,int nR,int nID){
	// stop:  目前範圍內剩下一個節點時
	if( nL+1==nR ){
		seg[nID]=num[nL];
		return ;
	}
	int nM=nL+nR>>1;
	BuildTree(nL,nM, nID<<1 );
	BuildTree(nM,nR,nID<<1|1);
	seg[nID]=max(seg[nID<<1],seg[nID<<1|1]);
}
int Query(int nL,int nR,int nID){
	// stop
	if(qL<=nL and nR<=qR)
		return seg[nID];
	int nM=nL+nR>>1;
	if( qR<=nM )
		return Query(nL,nM, nID<<1 );
	else if( nM<=qL )
		return Query(nM,nR,nID<<1|1);
	return max( Query(nL,nM, nID<<1 ), Query(nM,nR,nID<<1|1));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N, Q;
	
	cin>>N;
	for(int n=0; n<N; n++)
		cin>>num[n];
	// 左閉右開
	BuildTree(0,N,1);
	cin>>Q;
	while( Q-->0 ){
		cin>>qL>>qR;
		if( qL>qR )
			swap(qL,qR);
		qL-=1; //原始資料編號從０開始 
		cout<< Query(0,N,1) <<"\n";
	}
}


