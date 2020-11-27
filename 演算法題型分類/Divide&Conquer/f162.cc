#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e5;
const int MaxV=3e3;
const int MaxM=50;

vector<int> col[MaxM];
vector<int> tmp;
vector<int> prS;
int N, M, K;

void CDQ(int L,int R,int &ans){
	if(L==R){ ans=max(ans,prS[L]); return; }
	int M=(L+R)>>1;
	CDQ(  L,M,ans);
	CDQ(M+1,R,ans);
	int pL, pR;
	for(pL=L,pR=M+1; pL<=M and pR<=R; pL+=1){
		for(; pR<=R and prS[pR]-prS[pL]<=K; pR+=1)
			ans=max(ans,prS[pR]-prS[pL]);
	}
	pL=L, pR=M+1;
	int pM=L;
	while(pL<=M and pR<=R)
		tmp[pM++]=(prS[pL]<=prS[pR])? prS[pL++]: prS[pR++];
	while(pL<=M) tmp[pM++]=prS[pL++];
	while(pR<=R) tmp[pM++]=prS[pR++];
	for(pM=L;pM<=R;pM++) prS[pM]=tmp[pM];
}
int main(){
	
	int ans=0;
	scanf("%d\n%d %d\n",&K,&M,&N);
	for(int r=0;r<M;r++){
		col[r].resize(N);
		for(int c=0;c<N;c++)
			scanf("%d",&col[r][c]);
	}
	for(int r=1;r<M;r++)
		for(int c=0;c<N;c++)
			col[r][c]+=col[r-1][c];
	
	tmp.resize(N);
	prS.resize(N);
	for(int sr=-1;sr<M;sr++)
		for(int er=sr+1;er<M;er++){
			prS[0]=col[er][0]-((sr>=0)? col[sr][0]: 0);
            for(int c=1;c<N;c++)
				prS[c]=prS[c-1]+col[er][c]-((sr>=0)? col[sr][c]: 0);
			CDQ(0,N-1,ans);
		}
	printf("%d\n",ans);
}