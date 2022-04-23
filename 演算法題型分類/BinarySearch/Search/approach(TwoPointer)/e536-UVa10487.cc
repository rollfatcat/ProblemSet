/* 直覺(39ms)：暴力法
 * 枚舉 1e3 個數字挑選兩個數字做加總的和(共 5e5 個)
 * 排序上述的所有和後, 查詢時可以用二分搜尋法找到最近的值
 * 線性(2ms)：
 * 利用『兩數和』的性質, 線性掃描已經排序好的數列並找出差值最接近的答案
 */
#include<bits/stdc++.h>
using namespace std;
 
const int MaxN=1000;
const int MaxQ=25;
 
int org[MaxN];
int main(){
	int N, Q, target;
	for(int caseN=1;scanf("%d",&N) and N>0;caseN++){
		printf("Case %d:\n",caseN);
		for(int i=0;i<N;i++)
			scanf("%d",&org[i]);
		sort(org,org+N);
		for(scanf("%d",&Q);Q--;){
			scanf("%d",&target);
			/* 兩個指標初始狀態：(front=0,back=N-1), 固定front時將back一格格左移直到 總和 ≦ 目標值, 此時將front往右一格後重複上述步驟直到兩指標相遇, 過程中只要總和＝目標值時就能跳出迴圈, 因為目的是找到差值最小化(差值不可能小於0)。
			 */
			int ansS=1<<30, ansD=1<<30;
			int front=0, back=N-1;
			for(int tmpS; front<back; front++){
				for(tmpS=org[front]+org[back]; front<back and tmpS>target;tmpS=org[front]+org[--back])
					if(abs(target-tmpS)<ansD)
						ansS=tmpS, ansD=abs(target-tmpS);
				if(front<back and abs(target-tmpS)<ansD)
					ansS=tmpS, ansD=abs(target-tmpS);	
				if(ansD==0)
					break;
			}
			printf("Closest sum to %d is %d.\n",target,ansS);
		}
	}
}