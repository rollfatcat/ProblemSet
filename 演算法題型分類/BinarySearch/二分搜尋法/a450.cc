/* 給定Ｎ個數字和Ｑ次查詢，每次查詢Ｌ,Ｒ時輸出數列中落在範圍內的數字個數？
 * 解題關鍵：二分搜尋法STL
 * Ｑ=1e6 代表每次查詢的成本＝Ｏ(㏒Ｎ)
 * 需要使用二分搜尋法的前提就是排序Ｎ個數字
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxQ=1e6;
int num[MaxN];
int main(){
	int N, Q, cnt, qL, qR;
	scanf("%d %d\n",&N,&Q);
	for(int i=0;i<N;i++)
		scanf("%d",&num[i]);
	sort(num,num+N);
	while(Q-->0){
		scanf("%d %d\n",&qL,&qR);
		cnt=upper_bound(num,num+N,qR)-lower_bound(num,num+N,qL);
		(cnt==0)? puts("The candies are too short"): printf("%d\n",cnt);
	}
}