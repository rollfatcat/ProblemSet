/* 給定Ｎ個點和Ｍ條無(雙)向邊，Ｋ個設定有切換按鈕的編號，從１號點出發而且初始狀態為１，問抵達Ｎ號點的最短步數？
 * 無(雙)向邊通道是否開啟是由當下的狀態決定，按下按鈕後可以切換狀態
 * 解題核心：BFS + Status(抵達某個點時ｘ當下的狀態)
 * 若抵達的點設定有開關時可以透過「切換」變成另一種狀態，共享相同的步數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxM=2e5;
const int INF=1e9;
int stp[MaxN+1][2];
bool on[MaxN+1]={};
vector<int> to[MaxN+1][2];

struct STATUS{
	int e;
	bool t;
	STATUS(int e=0,bool t=0):e(e),t(t){}
} now;

int main(){
	int N, M, K, a, b, t;
	cin>>N>>M>>K;
	while(M-->0){
		cin>>a>>b>>t;
		to[a][t].push_back(b);
		to[b][t].push_back(a);
	}
	while(K-->0){
		cin>>a;
		on[a]=1;
	}
	// init
	for(int n=1; n<=N; n++)
		stp[n][0]=stp[n][1]=INF;
	
	stp[1][1]=0;
	deque<STATUS> Q={ STATUS(1,1) };
	if( on[1] ){
		stp[1][0]=0;
		Q.push_back( STATUS(1,0) );
	}
	while( !Q.empty() ){
		now=Q.front();
		Q.pop_front();
		for(int nxt: to[now.e][now.t]){
			if( stp[nxt][now.t]<INF )
				continue;
			stp[nxt][now.t]=stp[now.e][now.t]+1;
			Q.push_back( STATUS(nxt,now.t) );
		}
		if( !on[now.e] or stp[now.e][now.t^1]<INF)
			continue;
		now.t^=1;
		stp[now.e][now.t]=stp[now.e][now.t^1];
		for(int nxt: to[now.e][now.t]){
			if( stp[nxt][now.t]<INF )
				continue;
			stp[nxt][now.t]=stp[now.e][now.t]+1;
			Q.push_back( STATUS(nxt,now.t) );
		}
	}
	// output
	int ans=min(stp[N][0],stp[N][1]);
	cout<<( (ans==INF)? -1: ans );
}
