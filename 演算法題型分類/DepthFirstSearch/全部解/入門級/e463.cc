// 字串和數字的轉換, 練習暴力法(判斷如何設定停止條件)
#include<bits/stdc++.h>
using namespace std;

vector<long> ans;
inline void DFS(int bound,long now,int L){
	ans.push_back(pow(10,L)+now);
	for(int i=2;i<=bound;i++){
		long nxt=i*pow(10,L)+now;
		ans.push_back(nxt);
		DFS(i>>1,nxt,L+1+(i>9));
	}
}
int main(){
	for(int n;scanf("%d",&n)==1;){
		ans.clear();
		
		DFS(n>>1,n,1+(n>9)+(n==100));
		sort(ans.begin(),ans.end());
		printf("%lu\n%d",ans.size()+1,n);
		for(long x:ans)
			printf(" %ld",x);
		putchar('\n');
	}
}