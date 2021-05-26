/* 給定Ｎ張卡片的戰鬥力數值，每張卡片最多使用一次，輸出最小無法組合的數值？
 * 解題關鍵：暴力法枚舉(狀態轉移)＋排序
 * 初始狀態：能形成的最大組合數＝０
 * 狀態轉移：因為新數字存在時會讓"現有可以形成的所有組合數"加上這個新數字的關係形成的新狀態必須保持"連續性"
 *         換句話說，新數字必須不超過"現有可以形成的所有組合數"中最大值+1。
 *         這樣的狀態轉移在挑選新數字時必定是從Ｎ個數字中由小到大依序更新，所以需要把Ｎ個數字排序後處理。
 *         轉移後"現有可以形成的所有組合數"中最大值會是之前的最大值加上新數字。
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=2e5;
const int MaxC=1e9;
int num[MaxN];

int main(){
	int N;
	scanf("%d\n",&N);
	for(int i=0; i<N; i+=1)
		scanf("%d",&num[i]);
	sort(num,num+N);
	long now_v=0; // 能形成的最大組合數字，初始狀態＝０
	for(int v: num){
		if(v>now_v+1)
			break;
		now_v+=v;
	}
	printf("%ld\n",now_v+1);
}