#include <bits/stdc++.h>
using namespace std;

// 0 ≤ x ≤ y < 2^31
int main() {
	int caseT;
	
	scanf("%d\n",&caseT);
	while(caseT--){
		int x, y, L;
		scanf("%d %d\n",&x,&y);
		if(x==y){ puts("0"); continue; }
		y-=x;
		L=sqrt(y);
		x=y-L*L;
		printf("%d\n",(L<<1)-(x==0)+(x>L));
	}
}
