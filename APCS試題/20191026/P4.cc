#include<bits/stdc++.h>
using namespace std;

const int MaxN=25+1;
const int MaxM=25+1;
int M, N; // 2 ≦ N,M ≦ 25
int row[MaxN][MaxM];
int col[MaxN][MaxM];

bool v[MaxN][MaxM];
struct DATA{
    int L, R, U, D, cnt;
    DATA(int L=0,int R=0,int U=0,int D=0,int C=0):L(L),R(R),U(U),D(D),cnt(C){}
  	bool operator<(const DATA &rhs)const{ return cnt>rhs.cnt; }
} now, nxt;
DATA DeleteOne(int L,int R,int U,int D,int cnt,int idx=0){
		for(idx=L+1;idx<=R and v[U][L]==v[U][idx];idx++);
    if(idx==R+1 and D>U) return DeleteOne(L,R,U+1,D,cnt);
    for(idx=L+1;idx<=R and v[D][L]==v[D][idx];idx++);
    if(idx==R+1 and D>U) return DeleteOne(L,R,U,D-1,cnt);
    
    for(idx=U+1;idx<=D and v[U][L]==v[idx][L];idx++);
    if(idx==D+1 and R>L) return DeleteOne(L+1,R,U,D,cnt);
    for(idx=U+1;idx<=D and v[U][R]==v[idx][R];idx++);
    if(idx==D+1 and R>L) return DeleteOne(L,R-1,U,D,cnt);
    return DATA(L,R,U,D,cnt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin>>N>>M;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            cin>>v[i][j];
    // prefixsum of one
    for(int i=1;i<=N;i++)
    	for(int j=1;j<=M;j++)
    		row[i][j]=row[i][j-1]+v[i][j],
    		col[i][j]=col[i-1][j]+v[i][j];
		int ones, zero;
		// Priority_Queue
    priority_queue<DATA,vector<DATA>> PQ;
    PQ.push(DeleteOne(1,M,1,N,0));
    while(PQ.empty()==0){
    	now=PQ.top(); PQ.pop();
    	if(now.L==now.R or now.U==now.D){ 
    		cout<<now.cnt<<'\n'; break;
    	}
    	//
    	ones=col[now.D][now.L]-col[now.U-1][now.L];
    	zero=now.D-now.U+1-ones;
    	nxt=DeleteOne(now.L+1,now.R,now.U,now.D,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    	//
    	ones=col[now.D][now.R]-col[now.U-1][now.R];
    	zero=now.D-now.U+1-ones;
    	nxt=DeleteOne(now.L,now.R-1,now.U,now.D,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    	//
    	ones=row[now.U][now.R]-row[now.U][now.L-1];
    	zero=now.R-now.L+1-ones;
    	nxt=DeleteOne(now.L,now.R,now.U+1,now.D,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    	//
    	ones=row[now.D][now.R]-row[now.D][now.L-1];
    	zero=now.R-now.L+1-ones;
    	nxt=DeleteOne(now.L,now.R,now.U,now.D-1,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    }
}