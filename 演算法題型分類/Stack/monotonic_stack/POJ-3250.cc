/* 給定Ｎ個數字，輸出 每個數字和右側第一個大於等於目前數字的位置間差距的總和？
 * 解題關鍵：單調棧
 */
#include<iostream>
#include<stack>
using namespace std;

const int MaxN=8e4;
const int MaxH=1e9;
int hgt[MaxN];

int main(){
	
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)	
		scanf("%d",&hgt[i]);
    
	long long ans=0;
	stack<int> mts;
	for(int now=0; now<N; now++){
		for(; mts.empty()==0 and hgt[mts.top()]<=hgt[now]; mts.pop())
			ans+= now-mts.top()-1;
		mts.push(now);
	}
	for(; mts.empty()==0; mts.pop())
		ans+=N-mts.top()-1;
	printf("%lld\n",ans);
}