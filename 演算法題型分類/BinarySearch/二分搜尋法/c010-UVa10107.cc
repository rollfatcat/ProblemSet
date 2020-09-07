/* 每次輸入一個數字，該數字加入數列後輸出數列的中位數？
 * 中位數的定義：個數為奇數時輸出中間位置的數，偶數時則輸出前後兩個位置取平均。
 * 解題關鍵：中位數的定義＋二分搜STL
 * 中位數的定義＝數列位置中間
 * 二分搜查詢要插入的位置。
 */
#include<bits/stdc++.h>
using namespace std;

const long MaxN=1e4;
int main(){
	vector<int> num;
	int N;
	while(scanf("%d\n",&N)!=EOF){
		num.insert( lower_bound(num.begin(),num.end(),N),N );
		printf("%d\n",(num.size()&1)? num[num.size()>>1] : num[num.size()>>1]+num[(num.size()>>1)-1]>>1);
	}
}