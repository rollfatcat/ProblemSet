/* 給定Ｎ個數字
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e5;
bool show[MaxN+1]={}; // 某個數字是否已經出現過
int inv[2*MaxN+1]={}; // 這個位置為起點時會出現的逆數對
int pos[2*MaxN+1];    // 紀錄位置
int tmp[2*MaxN+1];    // MergeSort 用到的暫存區
int num[2*MaxN+1];    // 紀錄輸入的數列

/* 排序的陣列是 pos，因為我們需要對某個位置累加逆數對
 * 做合併時根據「位置指到的數字」小到大，每當左序列的數字加入「排序好」的序列，對該位置加上的逆數對 = 右側數列有多少個加入「排序好」的數列當中。
 */
void MergeSort(int L,int R){
	if(L==R) return;
	int M=(L+R)/2;
	MergeSort(  L,M);
	MergeSort(M+1,R);
	
	int Ti=L;
	int Li=L;
	int Ri=M+1;
	while( Li<=M and Ri<=R )
		if( num[ pos[Li] ]<=num[ pos[Ri] ] ){
			inv[ pos[Li] ]+=Ri-M-1;
			tmp[Ti++]=pos[Li++];
		}else
			tmp[Ti++]=pos[Ri++];
	while(Li<=M){
		inv[ pos[Li] ]+=R-M;
		tmp[Ti++]=pos[Li++];
	}
	while(Ri<=R) 
		tmp[Ti++]=pos[Ri++];
	/* Copy Back */
	for(Ti=L;Ti<=R;Ti++) 
		pos[Ti]=tmp[Ti];
}
int main(){
	int N;
	scanf("%d\n",&N); N*=2;
	for(int i=1;i<=N;i++){
		scanf("%d",&num[i]);
		pos[i]=i;
	}
	MergeSort(1,N);

	/* 數字第一次出現時加上該位置的逆數對，第二次時要扣除 */
	long ans=0;
	for(int i=1;i<=N;i++)
		ans+=(show[num[i]]==0)? inv[i]: -inv[i],
		show[num[i]]=1;
	printf("%ld\n",ans);
}
