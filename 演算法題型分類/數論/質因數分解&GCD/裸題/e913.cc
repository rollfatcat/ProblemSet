/* 給定Ｎ(Ｎ≤ 123456)，輸出Ｎ內符合質數對的數量。
 * 質數對＝(i,i-2)都是質數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=123456;

int main(){
	int N; scanf("%d",&N);
	
	vector<bool> NotP(N+1);
	for(int i=4;i<=N;i+=2)
		NotP[i]=1;
	for(int i=3;i<=sqrt(N);i+=2)
		if(NotP[i]==0)
			for(int j=3*i;j<=N;j+=2*i)
				NotP[j]=1;
	int cnt=0;
	for(int i=5;i<=N;i+=2)
		if(NotP[i]==0 and NotP[i-2]==0)
			cnt++;
	printf("%d\n",cnt);
}