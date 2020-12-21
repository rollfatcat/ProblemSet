/* 給定Ｎ把鑰匙和Ｍ棟房子，每棟房子會匹配到一把唯一的鑰匙，至少需要失敗幾次才能成功配對到所有房子？
 * 解題關鍵：等差級數
 * 第１棟房子至少要失敗Ｍ-１次，第２棟房子至少要失敗Ｍ-２次... (Ｍ-１+Ｍ-Ｎ)/２*Ｎ
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxT=1e5;
const int MaxN=1e5;
int main(){
	int caseT, N, M;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d\n",&N,&M);
		printf("%ld\n",(long)N*((M<<1)-N-1)>>1);
	}
}