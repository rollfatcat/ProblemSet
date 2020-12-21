/* a557 的簡化版
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=200;
const int MaxK=6;
int dpv[MaxN+1][MaxK+1]={};
int main(){
	dpv[0][0]=1;
	for(int add=1;add<=MaxN;add++)
		for(int sum=add;sum<=MaxN;sum++)
			for(int cnt=1;cnt<=MaxK;cnt++)
				dpv[sum][cnt]+=dpv[sum-add][cnt-1];
	for(int N,K;scanf("%d %d\n",&N,&K)!=EOF;)
		printf("%d\n",dpv[N][K]);
}