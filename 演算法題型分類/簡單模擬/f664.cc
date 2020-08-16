/* 給定Ｎ個氣溫的紀錄值，輸出每段"高峰時段"的氣溫紀錄？若不存在則輸出"0 0"
 * 高峰時段的定義為某個連續且相同的溫度，該時段前後兩天的氣溫都低於這個時段的溫度。
 * 解題關鍵：需要紀錄哪些"狀態"？
 * "時段"：紀錄起點(start)＋終點(end)
 * 前一個氣溫和目前氣溫的升/平/降(nxtDIR)
 * 前一個升/平/降的狀態(preDIR)
 * 由前往後掃描。
 *      若現在氣溫和前一天相同代表時段的結尾延後一天
 *      若現在氣溫和前一天不同代表可以判斷前一個時段是否為"高峰"並更新時段
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=31;
int N, num[MaxN];
int DIR(int now){ 
	if(num[now-1]==num[now]) return 0;
	return (num[now-1]<num[now])? 1: -1;
}
int main(){
	for(N=0;scanf("%d\n",&num[N])!=EOF;N++);
	int preDIR=0, nxtDIR;
	int start=0, end=0, ans_cnt=0;
	for(int pvt=1;pvt<N;pvt++){
		nxtDIR=DIR(pvt);
		if(nxtDIR==0)
			end=pvt;
		else{
			if(preDIR==1 and nxtDIR==-1){
				ans_cnt++;
				printf("%d",start+1);
				if(start!=end)
					printf(" %d",end+1);
				printf(" %d\n",num[start]);
			}
			preDIR=nxtDIR;
			start=end=pvt;
		}
	}
	
	if(ans_cnt==0) puts("0 0");
}