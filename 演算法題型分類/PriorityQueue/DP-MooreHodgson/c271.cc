/* 給定Ｎ個箱子的重量、負重、長度，輸出"限制下"時能夠疊起來後最多的箱子數？
 * 限制：疊箱子時須遵從由高到低非嚴格遞增的長度。
 * 解題關鍵：排序＋動態規劃(LIS)
 * 問題盲點：動態規劃前的排序規則(先依據長度由小到大，再依據負重小到大)＝烏龜塔問題(HooreHodgson)
 *      排序(動態規劃的更新順序)：更新該箱子時，其他箱子符合限制的箱子都要事先完成更新。
 *                       限制：長度小於等於該箱子長度 且 可以承受"額外負重"(負重扣除重量)的前提下最多的箱子數
 *      動態規劃：
 *          所有狀態＝疊ｉ個箱子時最少的重量總和是多少(越少越好，所以初始化時給極大值)
 *          狀態轉移＝只需考量從 箱子數＝１到目前最多能疊起來的箱子數，
 *                  枚舉每個狀態，考量該箱子"能選時"選或不選，能選＝疊上去時每個狀態的最少的重量總和
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxCaseT=1e2;
const int MaxN=1e3;
const int INF=(1<<31)-1;
struct BOX{
	int wght, load, leng;
	BOX(int a=0,int b=0,int c=0):wght(a),load(b),leng(c){}
	bool operator<(const BOX &rhs)const{ return (leng==rhs.leng)? load<rhs.load: leng<rhs.leng; }
} box[MaxN];
int dpv[MaxN+1];

int main() {
	int caseT, N, uN, W, S, L, maxL;
	scanf("%d\n",&caseT);
	while(caseT-->0){
		scanf("%d\n",&N);
		for(uN=0; N>0; N--){
			scanf("%d %d %d\n",&W,&S,&L);
			/* 題目會給"不合理"的箱子＝重量大於自身的負重 */
            if(S>=W)
				box[uN++]=BOX(W,S,L);
		}
		sort(box,box+uN);
		fill(dpv+1,dpv+uN+1,INF);
		maxL=0, dpv[0]=0;
		for(int i=0;i<uN;i++){
			/* 只需要更新從箱子數＝１到 目前疊起來最多的的箱子 */
            if(dpv[maxL]+box[i].wght<=box[i].load)
				dpv[maxL+1]=dpv[maxL]+box[i].wght;
			for(int nowL=maxL-1;nowL>=0;nowL--)
				if(dpv[nowL]+box[i].wght<=box[i].load)
					dpv[nowL+1]=min(dpv[nowL+1],dpv[nowL]+box[i].wght);
			/* 確認目前疊起來最多的的箱子數是否比前一個狀態多１個ㄋ */
            maxL+=(dpv[maxL+1]<INF);
		}
		printf("%d\n",maxL);
	}
}