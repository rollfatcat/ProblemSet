// 
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
int num[MaxN+1]={};
int main(){
	// 建表：由1e5往下更新,根據規則將數字ｉ算出生成數後用陣列紀錄
	for(int i=MaxN;i>0;i--){
		int now_v=i;
		for(int j=i;j>0;j/=10)
			now_v+=j%10;
		if(now_v<=MaxN)
			num[now_v]=i;
	}
	//
	int caseT, N;
	scanf("%d",&caseT);
	while(caseT--)
		scanf("%d",&N),
		printf("%d\n",num[N]);
}

