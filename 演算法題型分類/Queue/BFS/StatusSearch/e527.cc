/* 給定２個沒有刻度(只知最大容量)的容器(Ａ,Ｂ)，問最少要倒『幾次』才能讓容器內有Ｃ的容量？
 * 倒水規則：因為沒有顯示刻度，只能讓『倒滿』容器/ 『倒光』容器/ 倒向另一個容器直到空掉或是另一個倒滿
 * 解題關鍵：最少次數
 * 根據規則做狀態的展開，狀態＝兩個容器內的水量，展開有６種可能。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxV=1025;
const int INF=1<<30;
int A, B, C;
int on[MaxV+1][MaxV+1];
struct FLOW{
	int a, b;
	FLOW(int a=0,int b=0):a(a),b(b){}
} now, nxt;
void update(queue<FLOW>& Q,int& ans){
	if( on[nxt.a][nxt.b]<INF ) return;
	if( nxt.a==C or nxt.b==C ) ans=on[now.a][now.b]+1;
	on[nxt.a][nxt.b]=on[now.a][now.b]+1;
	Q.push(nxt);
}
int main(){
	int caseT, tmp;
	
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d %d %d\n",&A,&B,&C);
		for(int a=0; a<=A; a++)
			fill(on[a],on[a]+B+1,INF);
		int ans=-1;
		on[0][0]=0;
		queue<FLOW> Q;
		Q.push(FLOW());
		while(!Q.empty() and ans==-1){
			now=Q.front(); Q.pop();
			nxt=FLOW(A,now.b); update(Q,ans);
			nxt=FLOW(now.a,B); update(Q,ans);
			nxt=FLOW(0,now.b); update(Q,ans);
			nxt=FLOW(now.a,0); update(Q,ans);
			if(0<now.a and now.b<B){ // A to B
				tmp=min(now.a,B-now.b);
				nxt=FLOW(now.a-tmp,now.b+tmp);
				update(Q,ans);
			}
			if(0<now.b and now.a<A){ // B to Ａ
				tmp=min(now.b,A-now.a);
				nxt=FLOW(now.a+tmp,now.b-tmp);
				update(Q,ans);
			}
		}
		printf("%d\n",ans);
	}
}