/* 給定一個字串，輸出最長的(連續)子字串，字串內的相鄰字元為嚴格遞增且差值＝1
 * 若有數個相同長度則輸出最後一組答案。
 * 本題和 LIS 無關
 */
#include <bits/stdc++.h>
using namespace std;

const int MaxN=1e4;
char ss[MaxN];
int main(){
	while(scanf("%s\n",ss)!=EOF){
		int p1,p2,head=0, rear=1;
		for(p1=0,p2=1;ss[p2]!='\0';p2++){
			if(ss[p2]-ss[p2-1]!=1){
				if(p2-p1>=rear-head)
					head=p1, rear=p2;
				p1=p2;
			}
		}
		if(p2-p1>=rear-head)
			head=p1, rear=p2;
		
		printf("%d ",rear-head);
		for(;head<rear;head++)
			putchar(ss[head]);
		putchar('\n');
	}
}