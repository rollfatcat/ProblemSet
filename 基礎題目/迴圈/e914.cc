/* (A) 暴力法枚舉女兒的年齡(並同時獲得媽媽的年齡)，測試同時加上Ｎ後剛好是兩倍。
 * (B) 分析：假設媽媽年齡＝10x+y 且 女兒年齡＝10y+x 
 *          媽媽年齡至少 18 ≤ 10x+y 且媽媽不會活過99歲 10x+y+Ｎ ≤ 99
 *          根據題意：10x+y＞10y+x ... x＞y
 *                  10x+y+N＝2*(10y+x+N)＝20y+2x+2N ... 8x-19y＝N,{x,y}=[0:9] 
 *          枚舉 x=[0:9] 判斷 y是否存在"整數解"且0 ≤ y ≤ 9
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, x;
	while(scanf("%d\n",&N)!=EOF){
		for(x=1;x<=9;x++){
			y=((x<<3)-N)/19;
			if(0<=y and y<=9 and ((x<<3)-N)%19==0 and (10*x+y>=18) and (10*x+y+N)<=99){
				printf("%d\n",10*y+x); break;
			}
		}
		if(x==10) puts("no answer");
	}
}