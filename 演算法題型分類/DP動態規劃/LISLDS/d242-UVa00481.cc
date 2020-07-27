// 這題的輸入數量很大(500000) 時間必須壓在 N㏒N
// Robinson-Schensted-Knuth Algorithm : http://www.csie.ntnu.edu.tw/~u91029/LongestIncreasingSubsequence.html#3
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
int num[MaxN];
int cnt[MaxN];
int vec[MaxN];
int main(){
	scanf("%d\n",&num[0]);
	vec[0]=num[0], cnt[0]=1;

	int N=1, vecL=1, pos;
	for(; scanf("%d",&num[N])!=EOF; N++)
		if(num[N]>vec[vecL-1])
			vec[vecL]=num[N],
			cnt[N]=++vecL;
		else
			pos=lower_bound(vec,vec+vecL,num[N])-vec,
			vec[pos]=num[N],
			cnt[N]=pos+1;
		
		for(int i=N-1,L=vecL;L>0;i--)
			if(cnt[i]==L)
				vec[L--]=num[i];
		printf("%d\n-\n",vecL);
		for(int i=1;i<=vecL;i++)
			printf("%d\n",vec[i]);
}