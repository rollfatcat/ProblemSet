/* 給定參考點(Ｎ,Ｍ)和Ｑ個相對點(ｘ,ｙ)，輸出相對點在的方位？
 * 解題關鍵：二維座標判斷
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxQ=1e3;
const int MaxN=1e4;
const int MaxM=1e4;
int main(){
	int Q, N, M, x, y;
 
	while(scanf("%d\n",&Q) and Q>0){
		scanf("%d %d\n",&N,&M);
		while(Q-->0){
			scanf("%d %d\n",&x,&y);
			if(x==N or y==M){ 
				puts("divisa");
				continue; 
			}
			putchar( (y>M)? 'N':'S');
			putchar( (x>N)? 'E':'O');
			putchar('\n');
 
		}
	}
}