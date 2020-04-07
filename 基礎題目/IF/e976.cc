/* 給定Ｈ,Ｍ,Ｓ，詢問能不能在時間內抵達某地。
 * 0<Ｈ≤ 40000, 0<Ｍ≤ 2147483647, 0<Ｓ≤ 40000
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	char ss[2][20]={{" I will be late!"},{" I will make it!"}};
	for(int H,M,S;scanf("%d %d %d\n",&H,&M,&S)!=EOF;)
		printf("%d %d %d.%s\n",H,M,S,ss[H*S>=M]);
}