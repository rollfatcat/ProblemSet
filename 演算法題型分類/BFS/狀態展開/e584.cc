/* 一個正整數Ｘ若滿足下列條件：
 * 在Ｘ用10進位表示時，若Ｘ的每位數字都與前/後一位數字相差不超過1，則X是一個LunlunNumber (好lun的名字(X))
 * 給你一個正整數K，找出第K個LunlunNumber
 * 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
long memo[MaxN+1];
int main(){
	queue<long> Q;
	for(int i=1;i<=9;i++)
		Q.push(i);
	for(int lowbit,idx=1;idx<=MaxN;Q.pop(),idx++){
		memo[idx]=Q.front();
		lowbit=Q.front()%10;
		if(lowbit-1>=0) Q.push(10*Q.front()+lowbit-1);
		 Q.push(10*Q.front()+lowbit);
		if(lowbit+1<=9) Q.push(10*Q.front()+lowbit+1);
	}
	for(int N;scanf("%d\n",&N)!=EOF;)
		printf("%ld\n",memo[N]);
}