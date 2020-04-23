/* 給定Ｎ個數字，以最後一個數字(Ｂ)為單位，將每個位置是除以Ｂ餘數是１的數字加起來
 * 輸出 總和對Ｎ取餘數的位置和數值。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
const int MaxV=1e3;
int num[MaxN+1];
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;){
		for(int i=1;i<=N;i++)
			scanf("%d",&num[i]);
		int B=num[N],sum=0;
		for(int i=1;i<=N;i+=B)
			sum+=num[i];
		(sum%N==0)? printf("%d %d\n",N,num[N]): printf("%d %d\n",sum%N,num[sum%N]);
	}
}
