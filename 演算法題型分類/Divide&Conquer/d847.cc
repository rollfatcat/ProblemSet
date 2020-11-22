/* 給定Ｎ個二維平面的點，輸出每個點能「支配」的點數？
 * 支配的定義：點Ｂ支配點Ａ＝Ax<Bx and Ay<By
 * 解題關鍵：CDQ(偏維排序)
 * 根據第一維度小到大排序，針對第二維度做分治法。
 * 因為第一維度已經排序過，所有左半邊的第一維度一定會小於等於右半邊的第二維度
 * 而合併時會保證第二維度小到大，所以從右半邊的數字加入"排序"時對應位置需要加上左半邊有多少數字小於他。
 * 基於上述合併的特性，必須確保在排序第一維度數字相同時第二維度大到小，合併時才會優先處理(第一維度相同)第二維度較小者
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
int pos[MaxN][2];
int ord[MaxN];
int tmp[MaxN];
int cnt[MaxN];

bool compare(int a,int b){ 
  return (pos[a][0]==pos[b][0])? pos[a][1]>pos[b][1]:pos[a][0]<pos[b][0]; }
void CDQ(int L,int R){
	if(L==R) return;
	int M=L+R>>1;
	CDQ(  L,M);
	CDQ(M+1,R);
	
	int pL=L, pR=M+1;
	int pM=L;
	while(pL<=M and pR<=R){
		if( pos[ord[pL]][1]<pos[ord[pR]][1] ){
			tmp[pM++]=ord[pL++];
		}else{
			cnt[ord[pR]]+=pL-L;
			tmp[pM++]=ord[pR++];
		}
	}
	while(pL<=M)  tmp[pM++]=ord[pL++];
	while(pR<=R)  cnt[ord[pR]]+=M-L+1, tmp[pM++]=ord[pR++];
	
	for(pM=L;pM<=R;pM+=1) ord[pM]=tmp[pM];
}
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&pos[i][0],&pos[i][1]),
			ord[i]=i,
			cnt[i]=0;
		sort(ord,ord+N,compare);
		CDQ(0,N-1);
		for(int i=0;i<N;i++)
			printf("%d\n",cnt[i]);
	}
}