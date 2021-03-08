/* 給定Ｎ個數字和Ｑ次查詢，每次查詢時會給定範圍(qL/qR)輸出範圍內最大的連續區間和？
 * 解題關鍵：RMQ＋prefixsum
 * 連續區間和可以透過前綴和轉換為兩個數字相減，為了最大化差值只需要維護範圍內極值的位置
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxQ=1e5;
const int MaxV=1e9;
const long INF=(long)1<<60;

int qL, qR;
long prS[MaxN+2];
struct PAIR{ 
	int s, e;
	PAIR(int s=0,int e=0):s(s),e(e){}
	bool operator<(const PAIR &rhs)const{
		long ths_v=prS[e]-prS[s];
		long rhs_v=prS[rhs.e]-prS[rhs.s];
		return (ths_v!=rhs_v)? ths_v>rhs_v: (s!=rhs.s)? s<rhs.s: e<rhs.e;
	}
};
struct NODE{
	PAIR trp;
	int max_p, min_p;
} node[3*MaxN], ans;


void Build_Tree(int nL,int nR,int now){
	if(nL==nR){
		node[now].trp=PAIR(MaxN+1,nL);
		node[now].max_p=node[now].min_p=nL;
		return;
	}
	int nM=nL+nR>>1;
	int Lson=now<<1, Rson=now<<1|1;
	Build_Tree(  nL,nM,Lson);
	Build_Tree(nM+1,nR,Rson);
	
	node[now].min_p=(prS[node[Lson].min_p]<=prS[node[Rson].min_p])? node[Lson].min_p: node[Rson].min_p;
	node[now].max_p=(prS[node[Lson].max_p]>=prS[node[Rson].max_p])? node[Lson].max_p: node[Rson].max_p;
	node[now].trp=(node[Lson].trp<node[Rson].trp)? node[Lson].trp: node[Rson].trp;
	PAIR tmp=PAIR(node[Lson].min_p,node[Rson].max_p);
	if(tmp<node[now].trp)
		node[now].trp=tmp;
}
void Query_Tree(int nL,int nR,int now){
	if(qL<=nL and nR<=qR){
		if(node[now].trp<ans.trp)
			ans.trp=node[now].trp;
		if(ans.min_p<node[now].max_p){
			PAIR tmp=PAIR(ans.min_p,node[now].max_p);
			if(tmp<ans.trp)
				ans.trp=tmp;
		}
		if(prS[node[now].min_p]<prS[ans.min_p])
			ans.min_p=node[now].min_p;
		return;
	}
	int nM=nL+nR>>1;
	if(qL<=nM)Query_Tree(  nL,nM,  now<<1);
	if(nM<qR) Query_Tree(nM+1,nR,now<<1|1);
}


int main(){
	int N, Q;
	
	prS[0]=0;
	prS[MaxN+1]=INF;
	for(int caseI=1; scanf("%d %d\n",&N,&Q)!=EOF; caseI++){
		for(int i=1;i<=N;i++)
			scanf("%ld",&prS[i]),
			prS[i]+=prS[i-1];
		
		Build_Tree(0,N,1);
		printf("Case %d:\n",caseI);
		while(Q-->0){
			scanf("%d %d\n",&qL,&qR); qL-=1;
			ans={PAIR(MaxN+1,qL),qL,qL};
			Query_Tree(0,N,1);
			printf("%d %d %ld\n",ans.trp.s+1,ans.trp.e,prS[ans.trp.e]-prS[ans.trp.s]);
		}
	}
}

