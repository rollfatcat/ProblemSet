/* 解法：將黑牛的高度由低至高排序後, 計算相鄰的高度差
 * 排序高度差後, 輸出最大的高度差(需扣除掉白牛的數量)
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
int b_h[MaxN];

int main(){
	int N, c, h;
	scanf("%d",&N);
	
	int w_cnt=0, b_cnt=0;;
	for(int i=0;i<N;i++)
		scanf("%d %d",&c,&h),
		(c)? b_h[b_cnt++]=h: w_cnt++;
	if(w_cnt>=b_cnt-1){ puts("0"); return 0; }
	
	sort(b_h,b_h+b_cnt);
	for(int i=1;i<b_cnt;i++)
		b_h[i-1]=b_h[i]-b_h[i-1];
	b_cnt--;
	sort(b_h,b_h+b_cnt);
	printf("%d\n",b_h[b_cnt-1-w_cnt]);
}
/*
    5
    1 1
    1 2
    0 3
    1 4
    1 5
 */