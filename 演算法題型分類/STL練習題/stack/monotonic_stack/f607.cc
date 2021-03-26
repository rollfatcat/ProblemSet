/* 給定Ｎ個切點和長度Ｌ的棍子，
 *
 *  解題關鍵：monotonic-stack(單調棧)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5+2;
struct NODE{
	int ord, pos;
	bool operator<(const NODE &rhs)const{ 
		return pos<rhs.pos; }
} node[MaxN];

int main(){
	int N, L;
	
	scanf("%d %d\n",&N,&L);
	for(int i=1;i<=N;i++)
		scanf("%d %d\n",&node[i].pos,&node[i].ord);
	sort(node+1,node+N+1);
	
	long ansL=0;
	stack<int> mts;
	mts.push(0);
	for(int pvt=1; pvt<=N; pvt++){
		while(node[mts.top()].ord>node[pvt].ord){
			mts.pop();
			ansL+= node[pvt].pos-node[mts.top()].pos;
		}
		mts.push(pvt);
	}
	while(mts.top()>0){
		mts.pop();
		ansL+= L-node[mts.top()].pos;
	}
	printf("%ld\n",ansL);
}