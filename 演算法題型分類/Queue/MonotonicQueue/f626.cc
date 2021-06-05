/* 給定Ｎ個數字，連續Ｋ個為一組時組內的最大值和最小值差不超過Ｇ的組合數量？
 * 解題關鍵：單調列隊
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1e6;
const int MaxK=1e4;
const int MaxG=INT_MAX;
 
struct DATA{
	int v, p;
} now;
deque<DATA> maxQ; // 維護嚴格遞減
deque<DATA> minQ; // 維護嚴格遞增
 
int main(){
	int N, K, G;
	int ans=0;
 
	scanf("%d %d %d\n",&N,&K,&G);
	for(int i=0;i<N;i++){
		scanf("%d",&now.v); 
		now.p=i;
        /* 目前的最大值/最小值的位置已經超過Ｋ的範圍時則從"前面" pop() */
		if(maxQ.empty()==0 and i-maxQ.front().p>=K)
			maxQ.pop_front();
		if(minQ.empty()==0 and i-minQ.front().p>=K)
			minQ.pop_front();
        /* 用目前位置的值更新列隊內的值，方向為由後往前。
         * MaxQ 為嚴格遞增，MinQ 為嚴格遞減，值相同時則更新為當前位置 
         */
		while(maxQ.empty()==0 and maxQ.back().v<=now.v)
			maxQ.pop_back();
		maxQ.push_back(now);
		while(minQ.empty()==0 and minQ.back().v>=now.v)
			minQ.pop_back();
		minQ.push_back(now);
        /* 計算區間內最大值和最小值的差值是否超過Ｇ，前提需要確保區間長度＝Ｋ */
		ans+= (i>=K-1 and maxQ.front().v-minQ.front().v<=G);
	}
	printf("%d\n",ans);
}