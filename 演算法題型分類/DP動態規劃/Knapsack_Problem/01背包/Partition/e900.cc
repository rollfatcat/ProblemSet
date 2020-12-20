/* 給定Ｎ張卡片，每張卡片正反２面各自有點數(１-１３)，使得正反面點數總和差最小的前提下最少化翻牌次數？
 * 解題關鍵：01背包的變形題-分堆問題＋滾動陣列
 * 問題差異：選某張卡片正面的點數時是加上差值且翻牌次數不變，否則必定選擇反面，加上「負的差值」且次數多一。
 *         分堆問題時只要考慮選不選某個數字，不選時狀態不變，但這題不選時因為加上「負的差值」狀態會改變。
 * 狀態設定：狀態改變時會有負數，陣列不能存取負的位置所以需要做偏移，最糟糕的情況＝負最多時
 *         每張牌的範圍是(-１２，１２)，牌數最多１０００張，總和＝(−１２０００，１２０００) ... 陣列的空間要求
 *         base(偏移量)＝所有牌的負值總和。 
 *         初始狀態：用到的數字＝０(做完偏移後是 base)且該狀態下翻牌次數＝０
 *         cnt[ 目前使用的陣列 ][ 偏移後的數字 ]= 最少的翻牌次數
 * 狀態轉移：
 *   根據第ｉ張牌，只需更新 pvt (上一次有紀錄到的數字)，避免重複紀錄這一次更新到的狀態，只要檢查該格位置是否第一次更新。
 *   不翻：ｖ(新狀態)＝pvt+num[０][i]-num[１][i]且 翻牌次數不變
 *      cnt[now][v]=min(cnt[now][v],cnt[pre][pvt])
 *	 翻牌：ｖ(新狀態)＝pvt+num[１][i]-num[０][i]且 翻牌次數多一
 *      cnt[now][v]=min(cnt[now][v],cnt[pre][pvt]+1)
 *  輸出時從兩堆差值＝０，１(-1 or 1)... 依此類推直到找到第１個次數的狀態不是 INF 就是答案。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e3;
const int MaxD=12;
const int INF=1<<30;
/* 每張卡片都有２面的點數 */
int num[2][MaxN];
/* 滾動陣列做交替更新，所以都要宣告兩份 */
int cnt[2][2*MaxD*MaxN+1];
vector<int> memo[2];

int main(){
	int N, v;
	while(scanf("%d\n",&N)!=EOF){
		/* 讀取時同時計算偏移量 */
        int base=0;
		for(int i=0;i<N;i++)
			scanf("%d %d\n",&num[0][i],&num[1][i]),
			base+=abs(num[0][i]-num[1][i]);
		int bound=(base<<1)+1;
		/* 初始化 */
		memo[1]={base};
		cnt[1][base]=0;
		bool now=0, pre=1;
		for(int i=0;i<N;i++){
			/* 牌的正反面點數相同時可以無視這張牌 */
            if(num[0][i]==num[1][i]) continue;
			fill(cnt[now],cnt[now]+bound,INF);
			memo[now].clear();
			/* 根據前一次用到的數字做狀態更新，並只紀錄這一次更新到且不重複的數字 */
            for(int pvt:memo[pre]){
                /* 不翻牌 */
				v=pvt+num[0][i]-num[1][i];
                if(cnt[now][v]==INF)
					memo[now].push_back(v);
				cnt[now][v]=min(cnt[now][v],cnt[pre][pvt]);
				/* 翻牌 */
				v=pvt+num[1][i]-num[0][i];
				if(cnt[now][v]==INF)
					memo[now].push_back(v);
				cnt[now][v]=min(cnt[now][v],cnt[pre][pvt]+1);
			}
			swap(now,pre);
		}
		/* output */
		for(int i=0; i<=base; i++)
			if(cnt[pre][base+i]!=INF or cnt[pre][base-i]!=INF){
				printf("%d\n",min(cnt[pre][base+i],cnt[pre][base-i]));
				break;
			}
	}
}