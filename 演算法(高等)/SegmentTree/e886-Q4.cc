/* 掃描線＋線段樹：區間更新＋區間查詢，TIOJ-1224
 * 這題測資疑似有問題，實測後 0≦ X,Y≦ 1e6 且輸入的邊界左右或上下可能會顛倒...
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=15e4;
const int MaxX=2e5;
const int MaxSegNum=MaxX<<2;
int qL, qR, qV;

struct LINE{
	int sty, edy, pos, add;
	LINE(int sty=0,int edy=0,int pos=0,int add=-1):sty(sty),edy(edy),pos(pos),add(add){}
	inline bool operator<(const LINE &rhs)const{ return pos<rhs.pos;}
} line[MaxN<<1];
int cntv[MaxSegNum]={};
int lenv[MaxSegNum]={};

inline void Update(int nL,int nR,int idx){
	if(qL<=nL and nR<=qR){ cntv[idx]+=qV; return; }
	int nM=nL+nR>>1, Lson=idx<<1, Rson=Lson|1;
	if(qL<=nM) Update(  nL,nM,Lson);
	if(qR> nM) Update(nM+1,nR,Rson);
	lenv[idx]=(cntv[Lson]? (nM-nL+1): lenv[Lson])+
	          (cntv[Rson]? (nR-nM  ): lenv[Rson]);
}

int main(){
	int N, lx, ly, rx, ry;
	for(N=0;scanf("%d %d %d %d",&lx,&ly,&rx,&ry)!=EOF;)	
		line[N++]=LINE(ly,ry-1,lx, 1),
		line[N++]=LINE(ly,ry-1,rx,-1);
	
	sort(line,line+N);
	long sumArea=0;
	qL=line[0].sty,
	qR=line[0].edy,
	qV=line[0].add,
	Update(0,MaxX,1);
	
	for(int i=1;i<N;i++){
		sumArea+=(long)(line[i].pos-line[i-1].pos)*lenv[1];
		qL=line[i].sty,
		qR=line[i].edy,
		qV=line[i].add,
		Update(0,MaxX,1);
	}
	printf("%ld\n",sumArea);
}