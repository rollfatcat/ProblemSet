/* 給定Ｎ個蛋糕，能夠選取個數不超過Ｋ個蛋糕的總和最大值是多少？
 * 解題關鍵：前綴和＋單調列隊
 * Kadane's algorithm : 連續區間和透過前綴和轉換成兩數相減
 * 單調列隊 : 維護前Ｋ個範圍內的極值，計算每Ｋ個數字的差最大化
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e5;
const int MaxK=1e5;

int orgv[MaxN];
int PreS[MaxN];
int main(){
	PreS[0]=0;
	int N, K;
	
	while(scanf("%d %d\n",&N,&K)!=EOF){
		for(int i=1;i<=N;i++)
			scanf("%d",&orgv[i]),
			PreS[i]=PreS[i-1]+orgv[i];
		int ans=0;
		/* 移除時 */
        deque<int> DQ;
		DQ.push_back(0);
		for(int now=1;now<=N;now++){
			/* 當目前選取區間已經超過Ｋ個時，從前端移除位置 */
            if(DQ.empty()==0 and now-DQ.front()>K)
				DQ.pop_front();
			ans=max(ans,PreS[now]-PreS[DQ.front()]);
			while(DQ.empty()==0 and PreS[DQ.back()]>=PreS[now])
				DQ.pop_back();
			DQ.push_back(now);
		}
		printf("%d\n",ans);
	}
}