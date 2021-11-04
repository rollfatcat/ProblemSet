/* 給定Ｓ和Ｅ，數字可以透過加上自己的質因數(不包含１和自己)轉變為其他數字，輸出Ｓ變成Ｅ的最少轉變次數？
 * 解題關鍵：BFS
 * 轉變的方式＝加上不包含自己的質因數 ... 可以先用 vector 紀錄
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxS=1e2;
const int MaxT=1e3;
int stp[MaxT+1];
vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37};// 1000 以內的所有質數
 
vector<int> nxt[1001];
int main(){
  // 每個數字的質因數(因為展開時，若數字是質因數不能加上自己)
	for(int p: prime)
		for(int v=p<<1; v<=MaxT; v+=p)
			nxt[v].push_back(p);
	for(int p=33; p<=MaxT; p+=2){
		if(nxt[p].size()>0) continue;
		for(int v=p<<1; v<=MaxT; v+=p)
			nxt[v].push_back(p);
	}
  // main function
	int S, E;
	int caseI=1;
	while(scanf("%d %d",&S,&E) and S>0){
		printf("Case %d: ",caseI++);
		if(S>E){ puts("-1"); continue; }
		// BFS
		queue<int> Q;
		fill(stp+S,stp+E+1,-1);
		stp[S]=0;
		for(Q.push(S); Q.empty()==0 and stp[E]==-1; Q.pop()){
			int now=Q.front();
			for(int v: nxt[now])
				if(now+v<=E and stp[now+v]==-1){
					stp[now+v]=stp[now]+1;
					Q.push(now+v);
				}
		}
		printf("%d\n",stp[E]);
	}
}