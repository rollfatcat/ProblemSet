/* 給定Ｎ個二維平面上點的ＸＹ座標，輸出極大點的個數？
 * 極大點：該點的右上角不存在其他點(包含正上方和正右方)
 * 解題關鍵：排序＋掃描線
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=5e5;
int data[MaxN][2];
int ord[MaxN];
int ans[MaxN];

bool compare(int a,int b){ 
	return (data[a][0]==data[b][0])? data[a][1]<data[b][1]: data[a][0]<data[b][0]; }
int main(){
	int N;
	for(int caseI=1;scanf("%d\n",&N)!=EOF;caseI++){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&data[i][0],&data[i][1]),
			ord[i]=i;
		/* 排序規則：Ｘ座標由小到大 且 Ｙ座標由小到大 
		 * 根據極大點的定義位於當Ｘ座標相同時只需要紀錄Ｙ座標最大的點，
		 * 因為掃描線是由後往前移動，Ｙ座標最大的點必須排在後面(保證第一次掃瞄到就能讓水平線更新到最高)
		 */
		sort(ord,ord+N,compare);
		int ansL=0;
		int now_y=data[ ord[N-1] ][1];
		ans[ansL++]=ord[N-1];
		for(int i=N-2;i>=0;i--)
			if(data[ ord[i] ][1]>now_y)
				ans[ansL++]=ord[i],
				now_y=data[ ord[i] ][1];
		/* 若存在重複的座標的點時只需要輸出一個即可 */
		printf("Case %d:\nDominate Point: %d\n",caseI,ansL);
		for(int i=ansL-1;i>=0;i--)
			printf("(%d,%d)\n",data[ans[i]][0],data[ans[i]][1]);
	}
}
