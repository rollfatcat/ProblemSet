/* 種類：NPSC 國中組類似題(題目未提及解法但可以從測資觀察出方法)
 * 題目要求必須達到翻牌次數後最大化牌面的總和
 * 每張牌的分數 Xi，正面向上是正的，背面則是負的，n ≦ 1e4，k ≦ 1e9，-1e5 ≦ Xi ≦ 1e5
 * 核心解法：根據不同情況處理(有Cnt張分數一開始是負的，而翻牌次數是K)
 * (1) K ≦ Cnt，將所有的負數牌翻面
 * (2) K > Cnt，將所有的負數牌翻面後，多餘的次數都耗在絕對值離0最小的那張牌上
 *     每張牌的狀態都只有正面/背面兩種，只需要考慮『多餘次數』模二的餘數決定是否扣除
 */

#include<bits/stdc++.h> 
using namespace std;

const int MaxN=1e4;
const int MaxK=1e9;
int card[MaxN];
int CloseZero(int Base,int Len){
	if(Base==0)  return card[0];
	if(Base==Len)return -card[Len-1];
	return (-card[Base-1]<card[Base])? -card[Base-1]: card[Base];
}
int main(){
	
	for(int N, K;scanf("%d %d\n",&N,&K)!=EOF;){
		int CntNeg=0;
		for(int i=0;i<N;i++){
			scanf("%d",&card[i]);
			CntNeg+= card[i]<0;
			for(int j=i;j>0 and card[j]<card[j-1];j--)
				swap(card[j],card[j-1]);
		}
		
		int ans=0;
		if(CntNeg>=K){
			for(int i=0;i<K;i++)
				ans-=card[i];
			for(int i=K;i<N;i++)
				ans+=card[i];
		}else{
			for(int i=0;i<N;i++)
				ans+= (card[i]<0)? -card[i]: card[i];
			if( (K-CntNeg)&1 )
				ans-= CloseZero(CntNeg,N)<<1;
		}
		printf("%d\n",ans);
	}
	
}