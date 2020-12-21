// 經典動態規劃題目, 零錢兌換的方法數
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
long cnt[MaxN]={1};
int main(){
	// 建表
	for(int i=1;i*i*i<MaxN;i++)
		for(int j=i*i*i;j<MaxN;j++)
			cnt[j]+=cnt[j-i*i*i];
	// 根據輸入輸出方法數
	for(int N;scanf("%d\n",&N)!=EOF;)
		printf("%ld\n",cnt[N]);
}