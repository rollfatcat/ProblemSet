/* 題目會給定Ｎ個非負整數，輸出總和最大且最短的(非連續)子序列
 * 只要挑出正整數印出來即可，若整個序列都是０時則答案＝０
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
int v; // 0 ≤Ｘi ≤ 1e4

int main(){
	for(int N;scanf("%d\n",&N) and N;){
		bool AllZero=1;
		for(int i=0;i<N;i++){
			scanf("%d",&v);
			AllZero&=(v==0);
			if(v>0)  printf("%d ",v);
		}
		if(AllZero) putchar('0');
		putchar('\n');
	}
	
}
