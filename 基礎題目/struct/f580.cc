/* 給定Ｎ個骰子和Ｍ次的操作，輸出最後Ｎ個骰子朝上的面？
 * 操作根據ｂ判斷：
 *      ｂ＝-1，第ａ顆骰子向前旋轉
 *      ｂ＝-2，第ａ顆骰子向右旋轉
 *      ｂ >0， 交換第ａ顆骰子和第ｂ顆骰子的位置
 * 解題關鍵：模擬時骰子６面的狀態轉移時需要注意覆蓋順序 
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=20;
const int MaxM=100;
struct DICE{
	int s[6]={1,6,4,2,3,5}; // 上下前右後左
} dice[MaxN+1];
int main(){
	int N, M, a, b;
	scanf("%d %d\n",&N,&M);
	while(M-->0){
		scanf("%d %d\n",&a,&b);
		switch(b){
			case -1:// 向前旋轉
				b=dice[a].s[0]; // 先複製上面，等下會被覆蓋
				dice[a].s[0]=dice[a].s[4]; // 後面 ＞ 上面
				dice[a].s[4]=dice[a].s[1]; // 下面 ＞ 後面
				dice[a].s[1]=dice[a].s[2]; // 前面 ＞ 下面
				dice[a].s[2]=b;            // 上面 ＞ 前面
				break;
			case -2:// 向右旋轉
				b=dice[a].s[5]; // 先複製左面，等下會被覆蓋
				dice[a].s[5]=dice[a].s[1]; // 下面 ＞ 左面
				dice[a].s[1]=dice[a].s[3]; // 右面 ＞ 下面
				dice[a].s[3]=dice[a].s[0]; // 上面 ＞ 右面
				dice[a].s[0]=b;            // 左面 ＞ 上面
				break;
			default: 
				swap(dice[a],dice[b]);
		}
	}
	for(int i=1;i<=N;i++)
		printf("%d ",dice[i].s[0]);
}