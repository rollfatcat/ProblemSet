/* 題目敘述：
 * 2 ≦ M,N ≦ 25
 * 給定二維陣列的值 v[x][y]={0,1}
 * 當整行的數字都是0/1時可以整行消去,但每次消去時只能從"邊界"開始
 * 求改『最少格』後可以讓整張地圖被消除(只剩一行或一列)
 * 關鍵：
 * 題目要求最少的變更次數, 利用Heap維護所有狀態中改變次數最少格
 * 利用 PerfixSum 判斷某個區間內的數字是否相同, 避開使用迴圈
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=25+1;
const int MaxM=25+1;
int N, M; // 2 ≦ N,M ≦ 25
int row[MaxN][MaxM];
int col[MaxN][MaxM];

bool v[MaxN][MaxM];
struct DATA{
    int L, R, U, D, cnt;
    DATA(int L=0,int R=0,int U=0,int D=0,int C=0):L(L),R(R),U(U),D(D),cnt(C){}
  	bool operator<(const DATA &rhs)const{ return cnt>rhs.cnt; }
} now, nxt;
DATA DeleteEdge(int L,int R,int U,int D,int cnt,int ones=0){
	ones=row[U][R]-row[U][L-1];
		if((ones==(R-L+1) or ones==0) and D>U)
			return DeleteEdge(L,R,U+1,D,cnt);
    ones=row[D][R]-row[D][L-1];
    if((ones==(R-L+1) or ones==0) and D>U) 
    	return DeleteEdge(L,R,U,D-1,cnt);
    
    ones=col[D][L]-col[U-1][L];
    if((ones==(D-U+1) or ones==0) and R>L) 
    	return DeleteEdge(L+1,R,U,D,cnt);
    ones=col[D][R]-col[U-1][R];
    if((ones==(D-U+1) or ones==0) and R>L) 
    	return DeleteEdge(L,R-1,U,D,cnt);
    return DATA(L,R,U,D,cnt);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(cin>>N>>M){
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
    PQ.push(DeleteEdge(1,M,1,N,0));
    
    while(PQ.empty()==0){
    	now=PQ.top(); PQ.pop();
    	if(now.L==now.R or now.U==now.D){ 
    		cout<<now.cnt<<'\n'; break;
    	}
    	//
    	ones=col[now.D][now.L]-col[now.U-1][now.L];
    	zero=now.D-now.U+1-ones;
    	nxt=DeleteEdge(now.L+1,now.R,now.U,now.D,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    	//
    	ones=col[now.D][now.R]-col[now.U-1][now.R];
    	zero=now.D-now.U+1-ones;
    	nxt=DeleteEdge(now.L,now.R-1,now.U,now.D,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    	//
    	ones=row[now.U][now.R]-row[now.U][now.L-1];
    	zero=now.R-now.L+1-ones;
    	nxt=DeleteEdge(now.L,now.R,now.U+1,now.D,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    	//
    	ones=row[now.D][now.R]-row[now.D][now.L-1];
    	zero=now.R-now.L+1-ones;
    	nxt=DeleteEdge(now.L,now.R,now.U,now.D-1,now.cnt+min(ones,zero));
    	PQ.push(nxt);
    }
   
    }
}