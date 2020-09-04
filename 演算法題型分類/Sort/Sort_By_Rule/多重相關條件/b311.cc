/* 觀察題目可以發現：起始的強度和成長的幅度越高需要越往前處理
 * 解題關鍵：自定義排序
 * 根據代數，當目前強度是Ｘ時任意選取兩個城堡決定哪個負擔小就排前面，消去重複項後即可推導排序規則。
 * 但上述規則遇到(０,０)時會失效：任意城堡和(０,０)比較時都是False，而實際上(０,０)為優先處理的對象可以事先濾除。
 */
#include<bits/stdc++.h>
using namespace std;

const long MOD=1e8+7;
const int MAXN=100002;
struct NODE{
	int st, rd;
	bool operator<(const NODE &rhs)const{ return st*rhs.rd<rd*rhs.st; }
}castle[MAXN];

int main() {
	for(int N, uN; scanf("%d",&N)!=EOF;) {
		uN=0;
		while(N-->0){
			scanf("%d %d",&castle[uN].st,&castle[uN].rd);
			uN+= (castle[uN].st>0 or castle[uN].rd>0);
		}
		sort(castle,castle+uN);
		long t=0;
		for(int i=0;i<uN;i++)
			t=(t+castle[i].st+castle[i].rd*t%MOD)%MOD;
		printf("%lu\n",t);
	}
}