/* 動態規劃：最大化課堂的數量(選課時時段不能重疊,端點可以)
 * 利用 BIT 可以求得[0,S]之間的最大數值後更新 BIT[T]
 * 動態規劃前需要先排序Ｓ越前面越先更新。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
struct DATA{
	int D, S, T; // 1≤Ｄ≤5, 1≤Ｓ<Ｔ≤10
	bool operator<(const DATA &rhs)const{ return (S==rhs.S)?T<rhs.T:S<rhs.S; }
} data[MaxN];
int BIT[6][11]; 
int dpn[6][11];
inline int lowbit(int x){ return x&-x; }
inline int BIT_Query(int D,int P,int out=0){
	for(;P>0;P-=lowbit(P))
		out=max(out,BIT[D][P]);
	return out;
}
inline void BIT_Update(int D,int P,int v){
	if(v<dpn[D][P]) return;
	for(dpn[D][P]=v;P<=10;P+=lowbit(P))
		BIT[D][P]=max(v,BIT[D][P]);
}
int main(){
	int N, D, S, T;
	while(scanf("%d\n",&N)!=EOF){
		memset(BIT,0,sizeof(BIT));
		memset(dpn,0,sizeof(dpn));
		for(int i=0;i<N;i++)
			scanf("%d %d %d\n",&data[i].D,&data[i].S,&data[i].T);
		sort(data,data+N);
		for(int i=0;i<N;i++)
			BIT_Update(data[i].D,data[i].T,BIT_Query(data[i].D,data[i].S)+1);
		int cnt=0;
		for(D=1;D<=5;D++)
			cnt+=BIT_Query(D,10);
		printf("%d\n",cnt);
	}
}
