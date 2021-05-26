#include<bits/stdc++.h>
using namespace std;

const int MaxX=INT_MAX;
const int MaxA=INT_MAX;

int main(){
	int caseT;
	long a, x;
	
	scanf("%d",&caseT);
	while(caseT-->0){
		scanf("%ld %ld",&a,&x);
		x+= a*(a-1)>>1;
		printf("%ld\n",(long)ceil(sqrt(x<<1)-0.5) );
	}
}