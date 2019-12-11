#include<bits/stdc++.h>
using namespace std;
 
int main(){
	for(int a,b; scanf("%d %d",&a,&b)!=EOF;)
		printf("%d\n",(int)floor(b*log10(a))+1);
}