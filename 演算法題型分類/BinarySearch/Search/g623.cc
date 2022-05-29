/* 給定Ｎ個數字從中挑選出３個不同的數字，問有多少組合數？
 * 解題關鍵：枚舉中間的值，需要往前找到小於他的數字個數 和 往後找大於他的數字個數，方法數為兩者乘積
 * 排序Ｎ個數字，利用 lower_bound() 和 upper_bound() 往前後各自搜尋
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxT=20;
const int MaxN=1e5;
const int MaxA=1e9;

int A[MaxN];
int main(){
	int T, N, rear, back;
	long ans;
	
	scanf("%d",&T);
	while(T-->0){
		scanf("%d",&N);
		for(int n=0; n<N; n++)
			scanf("%d",&A[n]);
		sort(A,A+N);
		ans=0;
		for(int n=0; n<N; n++){
			rear=lower_bound(A,A+N,A[n])-A;
			back=upper_bound(A,A+N,A[n])-A;
			ans+= (long)rear*(N-back);
		}
		printf("%ld\n",ans);
	}
}