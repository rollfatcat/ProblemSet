/* 給定Ｎ個數字，問數列中不同數字的個數和 重複最多次的數字(依照輸入順序輸出)
 * 若所有數字都不同則輸出"NO"
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1000;
int memo[MaxN];
int cnt[MaxN];
int main(){
	for(int N;scanf("%d\n",&N)!=EOF;){
		int max_cnt=0, sz=0;
		for(int j,x,i=0;i<N;i++){
			scanf("%d",&x);
			for(j=0;j<sz and memo[j]!=x;j++);
			if(j==sz) memo[sz]=x, cnt[sz++]=0;
			cnt[j]++;
			if(cnt[j]>max_cnt) max_cnt=cnt[j];
		}
		printf("%d\n",sz);
		if(sz==N) 
			puts("NO");
		else{
			for(int i=0;i<sz;i++)
				if(cnt[i]==max_cnt)
					printf("%d ",memo[i]);
			putchar('\n');
		}
	}
}