/* 給定每格的供給(+)/需求數(-)，單位成本為移動一瓶葡萄酒時一格的距離，輸出最少的搬動成本？
 * 題目盲點：由最近的供給位置滿足需求，但注意若存在左側還有供給時優先從左側搬過來 ... 線性搜尋確認(x)
 * 解題關鍵：SweepLine + Queue
 * 避免出現"往返"的搬動方向 ... 依序由左到右滿足需求時需要優先消耗掉最左側的供給
 * 		需求和供給位置分開儲存，避免線性搜尋
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxA=1e3;
int num[MaxN];
int main(){
	int N;
	while(scanf("%d",&N) and N>0){
		queue<int> pos;
		queue<int> neg;
		for(int i=0; i<N; i+=1){
			scanf("%d",&num[i]);
			(num[i]<0)? neg.push(i): pos.push(i);
		}
		long ans=0;
		while(neg.empty()==0){
			while(pos.empty()==0 and num[pos.front()]<=-num[neg.front()]){
				ans+=num[pos.front()]*abs(neg.front()-pos.front());
				num[neg.front()]+=num[pos.front()];
				pos.pop();
			}
			if(pos.empty()==0)
				num[ pos.front() ]+=num[ neg.front() ];
			ans-=num[neg.front()]*abs(neg.front()-pos.front());
			neg.pop();
		}
		printf("%ld\n",ans);
	}
}