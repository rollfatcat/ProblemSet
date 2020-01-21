#include<bits/stdc++.h>
using namespace std;

const int MaxNum=1e9;
int main(){
	int caseT, num;
	scanf("%d",&caseT);
	while(caseT--)
		scanf("%d",&num),
		puts((num%3==1)?"NO":"YES");
}