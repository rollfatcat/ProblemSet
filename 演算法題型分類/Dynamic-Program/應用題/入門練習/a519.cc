/* 經典問題
 * 雄蜂只需要由雌蜂的未受精卵孵化，但雌蜂則需要由雄蜂和雌蜂的受精卵孵化
 * 給定Ｎ代表第Ｎ代祖先的數量＝費波納契數列
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=80;
long FIB[MaxN+1]={1,1,2,3};
int main(){
	for(int i=4;i<=MaxN;i++)
		FIB[i]=FIB[i-1]+FIB[i-2];
	for(int N;scanf("%d\n",&N) and N;)
		printf("%ld\n",FIB[N]);
}
