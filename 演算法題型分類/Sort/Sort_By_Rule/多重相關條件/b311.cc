/* 觀察題目可以發現：起始的強度和成長的幅度越高需要越往前處理
 * 根據需求自己定義排序規則：起始強度Ｘ成長幅度，當前述的數值相等時要先處理成長幅度高的
 * (99, 0) vs (0, 99)
 */
#include<bits/stdc++.h>
using namespace std;

const long MOD=100000007;
const int MAXN=100002;
struct NODE{
	int st, rd;
	bool operator<(const NODE &rhs)const{
		return (st*rhs.rd==rd*rhs.st)?(rd>rhs.rd):(st*rhs.rd<rd*rhs.st); }
}castle[MAXN];

int main() {
	for(int N; scanf("%d",&N)!=EOF;) {
		for(int i=0;i<N;i++)
			scanf("%d",&castle[i].st),
			scanf("%d",&castle[i].rd);
		sort(castle,castle+N);
		long t=0;
		for(int i=0;i<N;i++)
			t=(t+castle[i].st+castle[i].rd*t%MOD)%MOD;
		printf("%lu\n",t);
	}
}
// 75160921