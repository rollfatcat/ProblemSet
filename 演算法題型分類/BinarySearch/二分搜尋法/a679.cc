/* 給定Ｎ個線段的起點和終點，輸出重疊的組合數量？
 * 重疊的定義：區間內包含無數多個點 ≠ 端點重疊
 * 解題關鍵：排序＋二分搜尋法的STL
 * 排序：起點越小的優先處理，所以依據起點小到大排序。
 * 二分搜：查詢該線段的終點能涵蓋到其他(排序後號碼大於該線段的部分)線段起點的數量。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=3e4;
struct LINE{
	int st, ed;
} line [MaxN];
int sL[MaxN];

bool compare(LINE a,LINE b){ return a.st<b.st; }

int main(){
	int N, ans;
	for(int caseI=1; scanf("%d\n",&N)!=EOF; caseI++){
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&line[i].st,&line[i].ed);
		sort(line,line+N,compare);
		for(int i=0;i<N;i++)
			sL[i]=line[i].st;
		ans=0;
		for(int i=0;i<N;i++)
			ans+=lower_bound(sL+i,sL+N,line[i].ed)-sL-i-1;
		printf("Case %d: %d\n",caseI,ans);
	}
}