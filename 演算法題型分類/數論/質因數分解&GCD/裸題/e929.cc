#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e7;
inline int power(int &a,int b,int p=0){ 
	for(;a%b==0;a/=b,p++); return p;
}
inline void PrintPower(bool First,int base,int p){
	if(First==0){ printf(" * "); }
	printf("%d",base);
	if(p>1) printf("^%d",p);
}
int main(){
	int N; scanf("%d",&N);
	
	vector<bool> NotP(N+1);
	for(int i=4;i<=N;i+=2) 
		NotP[i]=1;
	for(int i=3;i<=sqrt(N);i+=2)
		if(NotP[i]==0)
			for(int j=3*i;j<=N;j+=2*i)
				NotP[j]=1;
	
	bool First=true;
	printf("%d = ",N);
	if((N&1)==0){ PrintPower(1,2,power(N,2)), First=0; }
	for(int p,i=3;i<=N;i+=2)
		if(NotP[i]==0 and (p=power(N,i)))
			PrintPower(First,i,p), First=0;
}