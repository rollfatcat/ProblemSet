#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5; // n ≤ 100000, 編號在輸⼊中會遞增
int num[MaxN];
int main(){
	int N, idx;
	while(scanf("%d\n%d",&N,&num[0])==2){
	if(N==2){
		printf("%d\n",(num[0]==1)? 2: 1);
	}else if(N==3){
		scanf("%d",&num[1]);
		long diff=num[1]-num[0];
		if(num[0]-diff>0){ printf("%d\n",num[0]-diff); }
		else printf("%ld\n",(diff&1==0)?(num[0]+diff/2):(num[1]+diff));
	}else{
		for(idx=1;idx<N-1;idx++)
			scanf("%d",&num[idx]);
		int diff=(num[N-2]-num[0])/(N-1);
		for(idx=1;idx<N-1 and num[idx]-num[idx-1]==diff;idx++);	
		if(idx<N-1)
			printf("%d\n",num[idx-1]+diff);
		else{
			printf("%d\n",(num[0]-diff>0)?(num[0]-diff):(num[N-2]+diff));
		}
	}
	}
}