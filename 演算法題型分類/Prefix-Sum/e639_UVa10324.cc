/* 給定由'0'和'1'構成的字串，詢問：區間內的子字串是否都是相同字元
 * 字串長度是1e6，所以 Query 時的效率必須是O(1)
 * 解答：利用前綴和計算區間內的有幾個'1'，
 *       (1) 區間內沒有'1'＝都是'0'，端點紀錄的個數相同
 *       (2) 區間內都是'1'，差值＝端點的差＋1
 */
#include <bits/stdc++.h>
using namespace std;
 
const int MaxL=1000000+5;
char ss[MaxL];
int sum[MaxL]={};

int main(){
	int Qnum, qL, qR, N;
	for(int caseI=1;scanf("%s",ss)!=EOF;caseI++){
		printf("Case %d:\n",caseI);
		for(int i=0;ss[i]!='\0';i++)
			sum[i+1]=sum[i]+(ss[i]=='1');
		for(scanf("%d\n",&Qnum);Qnum--;){
			scanf("%d %d\n",&qL,&qR);
			if(qL>qR) swap(qL,qR);
			N=sum[qR+1]-sum[qL];
			puts((N==0 or N==qR-qL+1)?"Yes":"No");
		}
	}
}