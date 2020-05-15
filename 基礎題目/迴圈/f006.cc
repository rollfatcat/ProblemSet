/* 給定Ｎ個數字，找出該數列中的極值(最大/最小值)
 * 初始化設定的練習
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
const int INF=1<<30;
int main(){
	int N, x;
	scanf("%d\n",&N);
	
	int maxv=-INF, minv=INF;
	for(int i=0;i<N;i++)
		scanf("%d",&x),
		maxv=max(maxv,x),
		minv=min(minv,x);
	printf("%d %d\n",maxv,minv);
}