/* 給定Ｎ個數字和Ｑ次的查詢，輸出每次查詢{ L, R, x }，Ｌ到Ｒ之間有多少個ｘ？
 * 解題關鍵：分段搜尋
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxQ=2e5;
int num[MaxN+1];
int pos[MaxN+1];
int main(){
	int N, Q, L, R, x, s, e;
	
	scanf("%d",&N);
	for(int n=1; n<=N; n++)
		scanf("%d",&num[n]);
	iota(pos+1,pos+1+N,1);
	sort(pos+1,pos+1+N,[&](int lhs,int rhs){
		return num[lhs]!=num[rhs]? num[lhs]<num[rhs]: lhs<rhs;
	});
	sort(num+1,num+1+N);
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%d %d %d",&L,&R,&x);
		s=lower_bound(num+1,num+1+N,x)-num;
		e=upper_bound(num+1,num+1+N,x)-num;
		if(s==e){ puts("0"); continue; }
		L=lower_bound(pos+s,pos+e,L)-pos;
		R=upper_bound(pos+s,pos+e,R)-pos;
		printf("%d\n",R-L);
	}
}