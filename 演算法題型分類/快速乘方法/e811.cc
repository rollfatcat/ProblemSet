/* 給定狀態轉移且當Ｎ極大時＝矩陣版本的快速幂次法
 * 但這題的狀態轉移中有做平移(包含常數)，無法以矩陣描述，故無法進行快速幂
 * 根據數論的『Pisano Period(皮薩諾週期)』：取模時會存在循環節(週期)
 * 週期＝存在一個最小的整數ｋ滿足 ƒ(k)＝ƒ(i) 且 ƒ(k+1)＝ƒ(i+1) 也就是相鄰兩數跟先前的某一組相鄰數一致。
 * 若 N ≦ k ，則在找周期的過程中我們便會知道所求；
 * 若 N ＞ k ，則可以根據週期求得所求。
 * 紀錄週期的方式：map< ƒ(k-1),ƒ(k) >＝k, 因為 1e8個 int 會被視為 RE
 */
#include<bits/stdc++.h>
using namespace std;

const int mod=1e4;
map<pair<int,int>,int> link;

int P, Q, R;
vector<int> memo(2);
int main(){
	long N;
	scanf("%d %d %d %d %d %ld\n",&P,&Q,&R,&memo[0],&memo[1],&N);
	link[ make_pair(memo[0],memo[1]) ]=1;
	
	int idx=2;
	for(int cycle,tag; idx<=N; idx++){
		memo.push_back( (P*memo[idx-1]+Q*memo[idx-2]+R)%mod );
		pair<int,int> now=make_pair(memo[idx-1],memo[idx]);
		if(link.find(now)!=link.end()){ 
			tag=link[now];
			N=(N-tag)%(idx-tag)+tag;
			break;
		}
		link[now]=idx;
	}
	printf("%04d\n",memo[N]);
}