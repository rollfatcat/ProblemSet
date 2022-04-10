/* 給定Ｎ個圓盤和Ｓ個步驟，輸出第Ｓ步驟時移動的圓盤編號？ 
 * 解題關鍵：遞迴 | 位元運算
 * 依照遞迴對現在的步驟討論
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=1e5;
const int MaxN=30;
int main(){
	int T, N, v;
	
	scanf("%d",&T);
	while(T-->0){
		scanf("%d %d",&N,&v);
		printf("%d\n",__lg(v&-v)+1);
	}
}
