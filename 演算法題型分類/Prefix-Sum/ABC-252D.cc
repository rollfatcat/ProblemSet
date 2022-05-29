/* 給定Ｎ個數字從中挑選出３個不同的數字，問有多少組合數？
 * 解題關鍵：枚舉中間的值，需要往前找到小於他的數字個數 和 往後找大於他的數字個數，方法數為兩者乘積
 * 題目的數字上限是 2e5 ，可以先利用 CountingSort 統計每個數字的個數後，prefix-sum 做前後數來的累計數
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxA=2e5;

int  cnt[MaxA+1]={};
int rear[MaxA+1]={};
int back[MaxA+1]={};

int main(){
	int N, v;
	
	scanf("%d",&N);
	while(N-->0){
		scanf("%d",&v);
		cnt[v]+=1;
	}
	for(v=1; v<=MaxA; v++)
		rear[v]=rear[v-1]+cnt[v];
	back[MaxA]=cnt[MaxA];
	for(v=MaxA-1; 0<=v; v--)
		back[v]=back[v+1]+cnt[v];
	long ans=0;
	for(v=1; v<MaxA; v++)
		ans+=(long)cnt[v]*rear[v-1]*back[v+1];
	printf("%ld",ans);
}