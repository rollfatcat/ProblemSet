/* 給定Ｎ個數字，輸出嚴格遞增子序列的長度和"最後一次"形成時的數列內容？
 * 解題關鍵：Robinson-Schensted-Knuth Algorithm
 * 因為Ｎ極大，查詢 LIS 時必須壓在Ｎ㏒Ｎ。
 * "由後往前"掃描做還原，第一個碰到的高度(由最高開始遞減)即是最後一次時的內容。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
int num[MaxN];
int cnt[MaxN];
int vec[MaxN];
int main(){
	/* 放一個數字到子序列中，避免空序列判斷問題 */
	scanf("%d\n",&num[0]);
	vec[0]=num[0], cnt[0]=1;

	int N=1, vecL=1, pos;
	for(; scanf("%d",&num[N])!=EOF; N++)
		if(num[N]>vec[vecL-1]){
			vec[vecL]=num[N];
			cnt[N]=++vecL;
		}else{
			pos=lower_bound(vec,vec+vecL,num[N])-vec;
			vec[pos]=num[N];
			cnt[N]=pos+1;
		}
		/* 由後往前掃瞄，掃描到第一個 LIS 等於目前"最大長度"時紀錄起來
		 * 因此越先記錄到的數字排在子序列越後面的位置。
		 */
		for(int i=N-1,L=vecL;L>0;i--)
			if(cnt[i]==L)
				vec[L--]=num[i];
		printf("%d\n-\n",vecL);
		for(int i=1;i<=vecL;i++)
			printf("%d\n",vec[i]);
}