/* 動態規劃＋N2方法：0.3s/816KB
 * 題目類似 a596 的概念, MaxCaseTｘMaxNｘMaxN > 1e8
 *
 * 動態規劃枚舉每個區間是否選取, DP紀錄的是選定這個區間時最大價值, 
 * 但選定的條件是該區間的開頭必須大於其他區間的結尾(也必定會大於其他區間的開頭)
 * 基於上述的狀態轉移需要『排序區間樓層』, 依據區間開頭由小到大排序.
 * 狀態轉移：只有當其他區間的結尾沒有覆蓋到現在區間的開頭時才能夠『選定該區間』
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxCaseT=50;
const int MaxN=3e4;
const int MaxA=1e5;
const int MaxC=1e3;
struct LINE{
	int st, ed, v;
	LINE(int s=0,int e=0,int v=0):st(s),ed(e),v(v){}
} line[MaxN];
int DP[MaxN];

bool compare(LINE &ths,LINE &rhs){ return ths.st<rhs.st; }
int main(){
	int caseT, N;
	scanf("%d",&caseT);
	for(int caseI=1;caseI<=caseT;caseI++){
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			scanf("%d %d %d",&line[i].st,&line[i].ed,&line[i].v);
			line[i].ed+=line[i].st-1;
		}
		sort(line,line+N,compare);
		int maxDP=0;
		for(int j,i=0;i<N;i++){
			DP[i]=line[i].v; 
			for(j=i-1;j>=0;j--)
				if(line[i].st>line[j].ed)
					DP[i]=max(DP[i],DP[j]+line[i].v);
			maxDP=max(maxDP,DP[i]);
		}
		printf("Case %d: %d\n",caseI,maxDP);
	}
}