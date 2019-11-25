#include<bits/stdc++.h>
using namespace std;

const int MaxLen=80+5;
char ss[MaxLen];
int main(){
	int caseT;
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%s",ss);
		int sum=0, cont=0;
		for(int i=0;ss[i]!='\0';i++)
			if(ss[i]=='O')
				++cont, sum+=cont;
			else
				cont=0;
		printf("%d\n",sum);
	}
}