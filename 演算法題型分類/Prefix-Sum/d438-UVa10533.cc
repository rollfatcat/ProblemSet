#include<bits/stdc++.h>
using namespace std;

const int MaxA=1e6;
bool NotP[MaxA+1]={1,1};
int prS[MaxA+1];
int SOD(int x,int ret=0){
	for(; x>0; x/=10)
		ret+=x%10;
	return ret;
}
int main(){
	// sieve
	for(int n=4; n<=MaxA; n+=2)
		NotP[n]=1;
	for(int n=3; n*n<=MaxA; n+=2){
		if( NotP[n] )continue;
		for(int p=n; n*p<=MaxA; p+=2)
			NotP[n*p]=1;
	}
	for(int n=2; n<=MaxA; n++)
		prS[n]=prS[n-1]+(NotP[n]==0 and NotP[SOD(n)]==0);
	//
	int caseT, L, R;
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%d %d",&L,&R);
		printf("%d\n",prS[R]-prS[L-1]);
	}
}