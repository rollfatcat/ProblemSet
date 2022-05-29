/* 給定Ｎ個數字，從中選出３個(可重複)填入空格內符合格式的 #組合
 * 解題關鍵：整除算式 = 利用篩法枚舉"倍數"關係
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
const int MaxA=2e5;
int cnt[MaxA+1]={};
int main(){
	int N, v;
	long ans=0;
	scanf("%d",&N);
	for(int n=0; n<N; n++){
		scanf("%d",&v);
		cnt[v]++;
	}
	for(int p=1; p<=MaxA; p++)
		for(int b=1; p*b<=MaxA; b++)
			ans+=(long)cnt[p*b]*cnt[p]*cnt[b];
	printf("%ld",ans);
}