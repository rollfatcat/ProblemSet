/* 給定Ｎ個碟盤(編號越大碟盤半徑越大)，遵從「河內塔規則」從Ａ柱移動到Ｃ柱的過程。
 * 河內塔規則：移動過程中編號大的碟盤不能疊在編號小的碟盤上方。
 * 解題關鍵：遞迴(基礎題)
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxN=15;
inline void Hanoi(int dish,char st,char tmp, char ed){
	if(dish>1)  Hanoi(dish-1,st,ed,tmp);
	printf("Move ring %d from %c to %c\n",dish,st,ed);
	if(dish>1)  Hanoi(dish-1,tmp,st,ed);
}
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		Hanoi(N,'A','B','C');
		putchar('\n');
	}
}
