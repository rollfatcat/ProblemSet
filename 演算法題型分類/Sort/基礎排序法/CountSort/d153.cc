/* #case=100, N=4e4
 * 題目提到：参加测验的奶牛都会得到一个分数（从0到100的整数）
 * 題目要求找到『中位數』，將目前分數的累積數量是否大於等於一半的總數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxScore=100+1;
int main(){
	int caseT, x, N;
	int cnt[MaxScore];
	
	scanf("%d",&caseT);
	while(caseT--){
		fill(cnt,cnt+MaxScore,0);
		scanf("%d",&N);
		for(int i=0;i<N;i++)
			scanf("%d",&x),
			cnt[x]++;
		N=(N>>1)+(N&1); // 需要贏過的個數
		int idx=0, sum=cnt[0];
		while(sum<N)
            sum+=cnt[++idx];
		printf("%d\n",idx);
	}
}