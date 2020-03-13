/* 給定Ｍ，接著每給一個Ｎ，
 * 如果Ｎ是Ｍ的倍數關係則輸出Ｎ/Ｍ，反之則輸出需要補多少才能成為Ｍ的倍數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxM=100;  // 1≦Ｍ≦100
const int MaxN=1000; // 1≦Ｎ≦1000
int main(){
	for(int M; scanf("%d\n",&M)!=EOF;)
		for(int N;scanf("%d",&N) and N;)
			printf("%d\n",(N%M)? M-N%M: N/M );
}