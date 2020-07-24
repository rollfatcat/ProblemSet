/* 給定兩列Ｍ個數字的數列，輸出有幾組符合條件的數對？
 * 條件：任選兩個位置(ＡＢ且Ａ<Ｂ)上列關係為小於且下列關係為大於 或者 上列關係為大於且下列關係為小於
 * 解題關鍵：上述的兩項條件可以透過『排序』後視為相同的關係
 * 排序規則：(1)若目前關係為 上列關係為小於且下列關係為大於 時交換ＡＢ位置則關係為 上列關係為大於且下列關係為小於
 *            維護上側數列為遞增時，找出下側數列的逆數對
 *         (2)數值可能重複，若上側數列的數對關係為相等時應該不列入計算，
 *            所以當上側數列數值相等時需同時將下側數列由小到大(消去逆數對)
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
int data[MaxN][2];
int ord[MaxN];
int tmp[MaxN];
long ans;

bool compare(int a,int b){ 
	return (data[a][0]==data[b][0])? data[a][1]<data[b][1]: data[a][0]<data[b][0]; }

void MergeSort(int nL,int nR){
	if(nL==nR) return;
	int nM=nL+nR>>1;
	MergeSort(  nL,nM);
	MergeSort(nM+1,nR);
	int p[3]={nL,nM+1,nL};
	while(p[0]<=nM and p[1]<=nR)
		if(ord[p[0]]<=ord[p[1]])
			tmp[p[2]++]=ord[p[0]++];
		else
			tmp[p[2]++]=ord[p[1]++],
			ans+= nM-p[0]+1;
	while(p[0]<=nM) 
		tmp[p[2]++]=ord[p[0]++];
	while(p[1]<=nR) 
		tmp[p[2]++]=ord[p[1]++];
	for(int i=nL;i<=nR;i++) 
		ord[i]=tmp[i];
}

int main(){
	for(int N, M;scanf("%d %d\n",&N,&M)!=EOF;){
		for(int i=0;i<N;i++)
			scanf("%d",&data[i][0]);
		for(int i=0;i<N;i++)
			scanf("%d",&data[i][1]),
			ord[i]=i;
		sort(ord,ord+N,compare);
		for(int i=0;i<N;i++)
			ord[i]=data[ord[i]][1];
		ans=0;
		MergeSort(0,N-1);
		printf("%ld\n",ans);
	}
}