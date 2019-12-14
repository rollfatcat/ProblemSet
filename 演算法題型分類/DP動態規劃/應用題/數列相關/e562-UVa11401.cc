/* 給 N根長度為1、2 ...、N的棍子,任選3根可以構成三角形的方法數
 * 標準動態規劃解, 狀態轉移：
 * 1. (不選定最長邊 N ) = N-1 根的方法數
 * 2. (選定最長邊 N ) = 枚舉剩餘2根的選取方法數
 *                      N-1時可以搭配 (2...N-2)
 *                      N-2時可以搭配 (3...N-3)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000000;
long cnt[MaxN+1]={}; // 注意方法數需要longlong儲存
int main(){
	//
	for(long i=4;i<=MaxN;i++)
		if(i&1) cnt[i]=cnt[i-1]+(i-3)*((i-2)/2+1)/2;
		else cnt[i]=cnt[i-1]+(i-2)*((i-4)/2+1)/2;
	//
	for(int N;scanf("%d",&N) and N>0;)
		printf("%ld\n",cnt[N]);
}