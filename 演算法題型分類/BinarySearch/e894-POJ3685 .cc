#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e4; //
const int INF=1<<30;
int N, M, B;
int base[MaxN];
inline int RowCount(int v){
	if(v<=0)  return 0;
	if(v>B )  return N;
	int tag=sqrt(v);
	return tag+(v>tag*(tag+1));
}
int main(){
	
	while(scanf("%d %d\n",&N,&M)!=EOF){
		B=N*(N-1);
		for(int i=0;i<N;i++)
			base[i]=(N-10000+i)*i;
		int nL=-INF, nR=INF;	
		while(nL<nR){
			int nM=(nL+nR)/2, cnt=0;
			if(nM<0) nM--;
			for(int i=0;i<N;i++)
				cnt+=RowCount(nM-base[i]);
			(cnt>=M)? nR=nM: nL=nM+1;
		}
		printf("%d\n",nL-1);
	}
}
