/* 給定Ｎ個點和Ｍ條"工作順序"(Ａ,Ｂ)代表完成Ｂ之前需要先完成Ａ，輸出工作的完成順序。
 * 題目保證若存在解答必定是唯一解，若是無解則必定存在環形路徑。
 * 解題核心：拓墣排序
 * 因為存在最多一解且不存在孤點(連通圖)，起點必定是沒有被指到的點(若不存在起點必定是因為環形路徑所致)
 * 若存在一條有向邊(Ａ,Ｂ)需要紀錄Ｂ的子點個數+1 和 Ａ有指向到Ｂ。
 * 所以當Ａ完成時該點移除後會導致相連的點受影響時需要將所有和Ａ相連點的子點個數-1，
 * 若因此而導致該相連點的子點個數=０代表他將會是下一個可以移除的點(可完成工作)。
 * 利用 BFS 從起點依序移除的點都記錄下來，若存在唯一解時移除的點數＝所有點數。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3+1;
const int MaxM=5e5;
int wait[MaxN];
vector<int> chd[MaxN];

int main(){
	int N, M, now;
	scanf("%d %d\n",&N,&M);
	for(int a,b;M-->0;){
		scanf("%d %d\n",&a,&b);
		chd[a].push_back(b);
		wait[b]++;
	}
	// 考慮「無解」的情況，無法直接在過程中根據順序輸出答案
	queue<int> Q, K;
	for(int i=1;i<=N;i++)
		if(wait[i]==0)
			Q.push(i);
	while(Q.empty()==0){
		now=Q.front(); Q.pop();
		K.push(now);
		for(int to:chd[now])
			if(--wait[to]==0)
				Q.push(to);
	}
	if(K.size()==N)
		for(puts("YES"); K.empty()==0; K.pop())
			printf("%d\n",K.front());
	else
		puts("NO");
}

