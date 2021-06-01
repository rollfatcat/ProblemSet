#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxM=2e5;

int play[MaxN+1]={};
int cnt[4]={};
struct EDGE{ int rhs, out; };
vector<EDGE> to[MaxN+1];

bool safe=true;
void DFS(int now){
	for(int i=0; i<to[now].size(); i+=1){
		int rhs_o=play[now]+to[now][i].out;
		rhs_o=(rhs_o==0)? 3 : (rhs_o==4)? 1: rhs_o;
		if( play[ to[now][i].rhs ]==0 ){
			play[ to[now][i].rhs ]=rhs_o;
			cnt[rhs_o]+=1;
			DFS(to[now][i].rhs);
		}else{
			safe&= play[ to[now][i].rhs ]==rhs_o;	
		}
	}
}
int main(){
	int N, M, a, b, c;
	// input
	scanf("%d %d",&N,&M);
	while(M-->0){
		scanf("%d %d %d",&a,&b,&c);
		to[a].push_back( {b,c} );
		to[b].push_back( {a,-c} );
	}
	// DFS
	int ans=0;
	for(int i=1; i<=N and safe; i+=1)
		if(play[i]==0){
			play[i]=cnt[1]=1;
			cnt[2]=cnt[3]=0;
			DFS(i);
			ans+= min( cnt[1],min(cnt[2],cnt[3]) );
		}
	printf("%d\n",(safe)? ans: -1);
}
