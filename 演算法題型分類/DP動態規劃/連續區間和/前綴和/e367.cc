#include <bits/stdc++.h>
using namespace std;
 
const int MaxB=1e5;
int num[MaxB+1];
int main(){
	for(int i=1;i<=MaxB;i++)
		num[i]=num[i-1]^i;
	for(int i=1;i<=MaxB;i++)
		num[i]^=num[i-1];
	for(int a,b;scanf("%d %d",&a,&b)==2;)
		printf("%d\n",num[b]^num[a-1]);
}