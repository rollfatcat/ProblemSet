/* 給定Ｎ個人的等級和可以提升的經驗值Ｃ，當每個人升級時需要的經驗值是和目前等級差的平方，問最大化最低等級的人時如何分配經驗值？
 * 解題關建：二分法
 * 單調性 ... 提升的等級越高需要的經驗值越多，但總和不可超過Ｃ
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e4;
const int MaxLV=1e7;
const long MaxC=1e14;
int lv[MaxN];

int main(){
	int N;
	long C;
	int nL=MaxLV;
	
	scanf("%d %ld",&N,&C);
	for(int i=0; i<N; i+=1){
		scanf("%d",&lv[i]);
		nL=min(nL,lv[i]);
	}
	int nR=nL+MaxLV;
	int ans=-1;
	while(nL<=nR){
		long nM=nL+nR>>1;
		long sumc=0;
		for(int i=0; i<N; i+=1)
			if(nM>lv[i])
				sumc+= (nM-lv[i])*(nM-lv[i]);
		if(sumc<=C){
			ans=nM;
			nL=nM+1;
		}else
			nR=nM-1;
	}
	printf("%d\n",ans);
}