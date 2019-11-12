/* 窮舉一些Ｎ可以看到，當Ｎ的尾數為９和０(相鄰的數字，例如 19 和 20 或是 29 和 30)時，他們產生出來的Ｎ-Ｍ之值(以下以 X 代稱 )皆相同，且其值皆為 9 的倍數。而其他的Ｎ-Ｍ皆是一對一對應。
 */
#include<bits/stdc++.h>
using namespace std;
 
int main(){
	long N;  // 1e1 ≦ N ≦ 1e18 
	while(scanf("%ld",&N) and N>0){
		if(N%9==0)
			printf("%ld ",10*N/9-1);
		printf("%ld\n",10*N/9);
	}
}