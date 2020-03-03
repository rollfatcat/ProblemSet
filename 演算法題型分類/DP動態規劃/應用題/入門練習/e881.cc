/* 動態規劃-走Ｍ步階梯方法數(但某些位階不能走＝方法數為０)
 * 觀察第３筆測資知道方法數會超過２^63 所以需要大數支援。 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1001;
const int MaxM=10;
const int MaxD=10;
const int base=1e9;

int broken[11];
inline void BigAdd(vector<int> &now,vector<int> &rhs,int carry=0){
	for(int i=now.size();i<rhs.size();i++)
		now.push_back(0);
	for(int i=0;i<rhs.size();i++)
		now[i]+=rhs[i]+carry,
		carry=now[i]/base, 
		now[i]%=base;
	for(int i=rhs.size();i<now.size() and carry>0;i++)
		now[i]+=carry,
		carry=now[i]/base, 
		now[i]%=base;
	if(carry>0) now.push_back(carry); 
}
int main(){
	int N, M, D, idx=0;
	scanf("%d %d\n%d",&N,&M,&D);
	for(int i=0;i<D;i++)
		scanf("%d",&broken[i]);
	broken[D]=MaxN;
	
	vector<int> one_num;
	vector<vector<int>> memo(N+1,one_num);
	
	memo[0].push_back(1);
	for(int now=1;now<=N;now++){
		if(now==broken[idx]){ idx++; continue; }
		memo[now]=memo[now-1];
		for(int i=2;i<=M and now-i>=0;i++)
			BigAdd(memo[now],memo[now-i]);
	}
	printf("%d",memo[N].back());
	for(int i=memo[N].size()-2;i>=0;i--)
		printf("%09d",memo[N][i]);
	putchar('\n');
}
/* === input 2 ===
   8 2 
   1 5
 */