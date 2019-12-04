#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1000;
int main(){
	
	int caseT;
	int num, v, cnt; // 0 < x ≤ 9999
	scanf("%d",&caseT);
	while(caseT--){
		scanf("%d",&num);
		for(cnt=0,v=num;v>0;v>>=1)
			cnt+=v&1;
		printf("%d ",cnt);
		for(cnt=0;num>0;num/=10)
			for(v=num%10;v>0;v>>=1)
				cnt+=v&1;
		printf("%d\n",cnt);
	}
}