/* 一個正整數Ｘ若滿足下列條件：
 * 在Ｘ用10進位表示時，若Ｘ的每位數字都與前/後一位數字相差不超過1，則X是一個LunlunNumber (好lun的名字(X))
 * 給你一個正整數K，找出第Ｋ個LunlunNumber
 * 解題關鍵：BFS(錯解)/DP(正解)
 * BFS 會根據"順序"展開，Ｋ不大可以暴力法線性搜尋
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxK=1e6;
long num[MaxK+5];
 
int main(){
	deque<long> Q;
	for(int i=1;i<=9;i+=1){
		num[i]=i;
		Q.push_back(i);
	}
	for(int v=10; Q.empty()==0 and v<=MaxK; Q.pop_front()){
		long now=Q.front();
		int last=now%10;
		if(last>0){
			Q.push_back(now*10+last-1);
			num[v++]=now*10+last-1;
		}
		Q.push_back(now*10+last);
		num[v++]=now*10+last;
		if(last<9){
			Q.push_back(now*10+last+1);
			num[v++]=now*10+last+1;
		}
	}
 
	int K;
	while(scanf("%d\n",&K)!=EOF)
		printf("%ld\n",num[K]);
}