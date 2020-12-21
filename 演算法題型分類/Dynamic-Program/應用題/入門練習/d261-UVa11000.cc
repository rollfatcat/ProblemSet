/* 標準動態規劃問題
 * 狀態轉移：每一年母蜂會生一隻公蜂, 而公蜂會生一隻公蜂和一隻母蜂,然後死去。但「初始」的母蜂永遠都不會死且每年都可以生一隻公蜂
 * 初始母蜂的增加部分額外計算。
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxCnt=(long)1<<32;
struct PAIR{
	long m, f;
	PAIR(long m=0,long f=0):m(m),f(f){}
};

int main(){
	// 建表：題目只保證答案 ≤ 2^32, 所以用vector儲存
	vector<PAIR> DP={PAIR()};
	while(DP.back().m<=MaxCnt)
		DP.push_back(PAIR(DP.back().m+DP.back().f+1,DP.back().m));
	// 根據詢問的Ｎ輸出
	for(int N;scanf("%d\n",&N)!=EOF and N>=0;)
		printf("%ld %ld\n",DP[N].m,DP[N].m+DP[N].f+1);
}