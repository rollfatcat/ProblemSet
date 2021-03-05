#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e4;
int num[MaxN];
 
int CDQ(int nL,int nR,int* part){
	if(nL==nR){
		part[0]=part[1]=num[nL];
		return num[nL];
	}
	int nM=nL+nR>>1;
	int data[2][2]; // {max, min}
	int out=max(CDQ(  nL,nM,data[0]),CDQ(nM+1,nR,data[1]));
	part[0]=max(data[0][0],data[1][0]);
	part[1]=min(data[0][1],data[1][1]);
	return max(out,data[1][0]-data[0][1]);
}
int main(){
	int N;
	while(scanf("%d\n",&N)!=EOF){
		for(int i=0;i<N;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<N;i++)	
			num[i]+=num[i-1];
 
		int data[2];
		printf("%d\n",max(0,CDQ(0,N-1,data)));
	}
}