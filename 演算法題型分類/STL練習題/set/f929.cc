/* 給定Ｎ格的初始值和Ｑ次操作，輸出查詢時陣列中第一個０的位置？
 * 1 x : 將陣列中第一個值是０位置的數值設定為 x
 * 2 x : 將陣列中第 x 個位置的數值設定為０
 * 3   : 輸出陣列中第一個值是０的位置
 * 解題關鍵：set
 * 容器必須支援 找到最小值/刪除指定數字/插入數字 ... set
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e6;
const int MaxQ=1e5;
int num[MaxN];
int main(){
	int N, Q, opt ,x;
	set<int> memo;
	
	scanf("%d",&N);
	for(int i=0; i<N; i+=1){
		scanf("%d",&num[i]);
		if(num[i]==0)
			memo.insert(i);
	}
	scanf("%d",&Q);
	while(Q-->0){
		scanf("%d",&opt);
		switch(opt){
			case 1:
				scanf("%d",&x);
				if(memo.empty()==0 and x!=0){
					num[ *memo.begin() ]=x;
					memo.erase(memo.begin());
				}
				break;
			case 2:
				scanf("%d",&x);
				if(num[x]!=0){
					num[x]=0;
					memo.insert(x);
				}
				break;
			default:
				printf("%d\n",(memo.empty()==0)? *memo.begin(): -1);
		}
	}
}