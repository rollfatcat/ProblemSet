/* 給定Ｎ個數字(１到Ｎ不重複出現的排列)，每當第０格數字換到數列最後時輸出當時數列中的逆數對？
 * 解題關鍵：BIT 計算小於現在這個位置的個數總和
 * 需要算出每個位置，向左和向右小於目前該位置數字的個數 ... 討論當該位置換到最後時的情況
 * 原本右側小於該位置數字的個數會因為後置的關係，需要從逆數對中扣除，而大於的個數則需要加入
 * 原本左側小於該位置數字的個數會因為後置的關係，需要加回(彌補該位置之前的後置扣除的關係)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e5;
int N;
int num[MaxN];
int ord[MaxN];
int tmp[MaxN];
int Less[MaxN]={};
int Ress[MaxN]={};

void CDQ(int nL,int nR){
	if(nL==nR) return;
	// Divide
	int nM=nL+nR>>1;
	CDQ(  nL,nM);
	CDQ(nM+1,nR);
	// Conquer
	int pM=nL;
	int pL=nL;
	int pR=nM+1;
	while(pL<=nM and pR<=nR){
		if(num[ ord[pL] ]<num[ ord[pR] ]){
			Ress[ord[pL]]+= pR-nM-1;
			tmp[pM++]=ord[pL++];
		}else{
			Less[ord[pR]]+= pL-nL;
			tmp[pM++]=ord[pR++];
		}
	}
	while(pL<=nM){
		Ress[ord[pL]]+= nR-nM;
		tmp[pM++]=ord[pL++];
	}
	while(pR<=nR){
		Less[ord[pR]]+= pL-nL;
		tmp[pM++]=ord[pR++];
	}
	// copy back
	for(pM=nL; pM<=nR; pM+=1)
		ord[pM]=tmp[pM];
}
int main(){
	scanf("%d",&N);
	for(int n=0; n<N; n+=1)
		scanf("%d",&num[n]);
	iota(ord,ord+N,0);
	CDQ(0,N-1);
	
	long ans=0;
	for(int n=0; n<N; n+=1)
		ans+=Ress[n];
	printf("%ld\n",ans);
	for(int n=0; n<N-1; n+=1){
		ans+=N-1-(Less[n]+Ress[n]<<1);
		printf("%ld\n",ans);
	}
}