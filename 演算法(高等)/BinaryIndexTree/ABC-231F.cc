/* 給定Ｎ件禮物每件禮物對Ａ和Ｂ都有個印象分數，如何分配給Ａ和Ｂ他們才不會打架？
 * 不會衝突的情況：禮物Ｘ給Ａ且禮物Ｙ給Ｂ時 Ax ≥ Ay and Bx ≤ By 的組合數，且 Ｘ=Ｙ 是合法的
 * 解題關鍵：inversion pair-like(逆數對)
 * 根據Ｘ座標由小到大排序後，相同Ｘ座標對應的Ｙ座標一起更新後再做查詢。
 * Ｙ座標要找逆數對(包含等於自己的所有個數)，透過 BIT 實現 RSQ
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=2e5;
const int MaxA=1e9;
vector<vector<int>> num(MaxN,vector<int>(2));
 
int srt[MaxN];
int BIT[MaxN+1];
inline int lowbit(int x){ return x&-x; }
void BIT_solve(vector<int>& vec,int& N,long& ans){
	// BIT_update
	for(int p : vec)
		for(p+=1; p<=N; p+=lowbit(p))
			BIT[p]+=1;
	// BIT_query
	for(int p : vec)
		for(p+=1; p>0; p-=lowbit(p))
			ans+=BIT[p];
	vec.clear();
}
int main(){
	int N;
 
	scanf("%d",&N);
	for(int n=0; n<N; n+=1)
		scanf("%d",&num[n][0]);
	for(int n=0; n<N; n+=1){
		scanf("%d",&num[n][1]);
		srt[n]=num[n][1];
	}
	sort(num.begin(),num.begin()+N);
	// 離散化
	sort(srt,srt+N);
	int uN=unique(srt,srt+N)-srt;
 
	long ans=0;
	num[N-1][1]=lower_bound(srt,srt+uN,num[N-1][1])-srt;
	vector<int> memo={num[N-1][1]};
	for(int n=N-2; n>=0; n-=1){
		num[n][1]=lower_bound(srt,srt+uN,num[n][1])-srt;
		if(num[n][0]!=num[n+1][0])
			BIT_solve(memo,N,ans);
		memo.push_back(num[n][1]);
	}
	BIT_solve(memo,N,ans);
	printf("%ld\n",ans);
}