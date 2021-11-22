/* 給定Ｑ次的查詢和格子的數量Ｎ，不能連續塗黑時輸出塗色的方法數(不可全數都不染色)？
 * 解題關鍵：費波那契數列＋快速幂
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxQ=3e5;
const long MaxN=1e18;
const int MOD=998244353;
long m[70][2][2]={{},{{1,1},{1,0}}};

int main(){
	for(int n=2; n<=63; n+=1){
		m[n][0][0]=(m[n-1][0][0]*m[n-1][0][0]+m[n-1][0][1]*m[n-1][1][0])%MOD;
		m[n][0][1]=(m[n-1][0][0]*m[n-1][0][1]+m[n-1][0][1]*m[n-1][1][1])%MOD;
		m[n][1][0]=(m[n-1][1][0]*m[n-1][0][0]+m[n-1][1][1]*m[n-1][1][0])%MOD;
		m[n][1][1]=(m[n-1][1][0]*m[n-1][0][1]+m[n-1][1][1]*m[n-1][1][1])%MOD;
	}
	int Q;
	long N;
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%ld",&N);
		vector<long> v={1,1};
		for(int n=1; N>0; N>>=1, n+=1){
			if((N&1)==0) continue;
			vector<long> t(2);
			t[0]=(m[n][0][0]*v[0]+m[n][0][1]*v[1])%MOD;
			t[1]=(m[n][1][0]*v[0]+m[n][1][1]*v[1])%MOD;
			v=t;
		}
		printf("%ld\n",v[0]-1);
	}
}	