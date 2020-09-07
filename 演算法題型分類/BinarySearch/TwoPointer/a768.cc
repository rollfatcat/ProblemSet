/* 給定Ｎ個不重複的邊長，輸出任選３邊剛好可以形成直角三角形的組合數量？
 * 解題關鍵：TwoPointer(爬行法) 14ms
 * 枚舉最長邊平方(總和固定)，輸出有幾組短邊平方＋次短邊平方剛好相等。
 * 利用『兩數和』的性質, 線性掃描已經排序好的數列並找出和剛好是最長邊平方的值
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e3;
long len[MaxN];
long sqr[MaxN];
int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=0;i<N;i++)
		scanf("%ld",&len[i]);
	sort(len,len+N);
	for(int i=0;i<N;i++)
		sqr[i]=len[i]*len[i];
	/* TwoPointer */
	int ans=0;
	for(int pvt=2;pvt<N;pvt++){
		int front=0, back=pvt-1;
		while(front<back)
			if(sqr[front]+sqr[back]<sqr[pvt])
				front++;
			else if(sqr[front]+sqr[back]>sqr[pvt])
				back--;
			else{ //sqr[front]+sqr[back]==sqr[pvt]
				front++; back--; ans++;
			}
	}
	printf("%d\n",ans);
}