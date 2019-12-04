#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=20;
const int MaxLen=20;
char ss[2][MaxLen+2];
inline bool IsVowel(char ch){
	return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
}
int main(){
	int caseT;
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%s\n%s",ss[0],ss[1]);
		if(strlen(ss[0])!=strlen(ss[1])){
			puts("No"); continue;
		}
		bool IsYes=true;
		for(int i=0;IsYes and ss[0][i]!='\0';i++){
			if( IsVowel(ss[0][i]) and IsVowel(ss[1][i]) )
				continue;
			IsYes&= ss[0][i]==ss[1][i];
		}
		(IsYes)? puts("Yes"): puts("No");
	}
}
