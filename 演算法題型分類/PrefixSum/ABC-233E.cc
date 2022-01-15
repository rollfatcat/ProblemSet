#include<bits/stdc++.h>
using namespace std;

const int MaxS=5e5;
char ss[MaxS+2];
long prS[MaxS+2];
int main(){
	int p;
	
	scanf("%s",ss);
	prS[0]=0;
	for(p=0; ss[p]!='\0'; p+=1)
		prS[p+1]=prS[p]+ss[p]-'0';
	for(   ; p>0; p-=1){
		prS[p-1]+=prS[p]/10;
		prS[p]=prS[p]%10;
	}
	
	for(p=prS[0]==0; ss[p]!='\0'; p+=1)
		printf("%ld",prS[p]);
	printf("%ld",prS[p]);
}