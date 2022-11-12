/* 給定Ｎ段「連續」總和的算式，能否透過調整Ｍ個算式恰好「湊出」１到Ｎ的總和？
 * 「連續」總和的算式 = 兩個點之間存在一條邊，維護左閉右開
 * 題目的要求可以轉換為是否可以從１走到Ｎ號點
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxM=2e5;

vector<int> to[MaxN+1];
bool vis[MaxN+1]={};
int main(){
	int N, M, l, r, now;
	
	scanf("%d %d",&N,&M);
	while(M-->0){
		scanf("%d %d",&l,&r);
		to[l-1].push_back(r);
		to[r].push_back(l-1);
	}
	
	deque<int> Q={0};
	while(Q.empty()==0){
		now=Q.front(); 
		Q.pop_front();
		for(int nxt: to[now])
			if(vis[nxt]==0){
				vis[nxt]=1;
				Q.push_back(nxt);
			}
	}
	puts((vis[N])?"Yes":"No");
}

