/* 給定維度Ｄ切割Ｃ次時可以產生的空間數
 * 當維度Ｄ時試圖切割第Ｃ次時子空間個數除了繼承前Ｃ-1次的子空間外
 * 還需要考慮"新增的超平面"會和切割Ｃ-1次形成的所有子區域個數形成交會。
 * 與其他Ｃ-1個Ｄ維超平面交會時，其情況為Ｃ-1個Ｄ-1維的超平面。
 * 遞迴式： ƒ(Ｄ,Ｃ)＝ƒ(Ｄ,Ｃ-1)＋ƒ(Ｄ-1,Ｃ-1) 且 ƒ(Ｄ,Ｃ)＝1,Ｄ=0 或是 Ｃ=0。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxD=50;
const int MaxC=50;

long dpv[MaxD+1][MaxC+1]={};
int main(){
	for(int D=1;D<=MaxD;D++)
		dpv[1][D]=D+1;
	for(int D=2;D<=MaxD;D++)
		for(int C=1;C<=MaxC;C++)
			dpv[D][C]=(D>=C)? ((long)1<<C): dpv[D][C-1]+dpv[D-1][C-1];
	
	for(int Q; scanf("%d\n",&Q)!=EOF;){
		for(int D,C;Q--;)
			scanf("%d %d\n",&D,&C),
			printf("%ld\n",dpv[D][C]);
	}
}
