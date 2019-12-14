#include<bits/stdc++.h>
using namespace std;

const int MaxL=50;
int num[MaxL];
int main(){
	int caseT, N;
	scanf("%d",&caseT);
	while(caseT--){
		int ans=0;
		scanf("%d",&num[0]);
		for(int i=1;i<N;i++){
			scanf("%d",&num[i]);
			for(int j=i-1;j>=0 and num[j]>num[j+1];j--,ans++)
				swap(num[j],num[j+1]);
		}
		printf("Optimal train swapping takes %d swaps.\n",ans);
	}
}