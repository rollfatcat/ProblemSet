/* 給定ＭxＮ的棋盤問彼此不會相互攻擊的前提下『最多』可以放的騎士數量
 * 非BFS, 分Case討論皆採用Greedy
 * (1) #row=1 or #column=1, 每格都可以放 
 * (2) #row=2 or #column=2, 2x2的間隔放
 * (3) Other, 只放在 x+y=odd 的格子＝(總數/2)+(總數==1)
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=500;
const int MaxM=500;
inline int Case2(int x){ return (x&3)? (x>>2<<1)+2: (x>>2<<1)+1; }
int main(){
	for(int N,M,x; scanf("%d %d\n",&M,&N) and M>0;){
		if(M==1 or N==1) x=M*N;
		else if(M==2 or N==2) x=Case2(M-1)*Case2(N-1); 
		else x=(N*M>>1)+(N*M&1);
		printf("%d knights may be placed on a %d row %d column board.\n",x,M,N);
	}
}