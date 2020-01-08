/* 題目本身和01背包無關, 但與主題相關可作為比較題。
 * 給定Ｎ個不同面額的貨幣, 並規定『提款方式』下一次提款前提下最多可以換得的貨幣種類
 * 觀察提款方式可以發現：提取金額Ｘ往下遞迴時必定是現有幣值中最大面額Ｙ的餘數，因為最小幣值是1，所以保證一定可以兌換完。
 * 題目所求則根據該方式反推：若目前的幣值>已經選取幣值的總和時則將該幣值加入, 若沒有則直接替換已選取幣值中面額最大者＝貪婪法
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1000;
int main(){
	int caseT, N, now_coin;
	for(scanf("%d\n",&caseT);caseT>0;caseT--){
		scanf("%d\n%d",&N,&now_coin);
		int last_coin=now_coin;
		int sumv=last_coin;
		int cnt=1;
		for(int i=1;i<N;i++){
			scanf("%d",&now_coin);
			(now_coin>sumv)? cnt++: sumv-=last_coin;
			sumv+=now_coin;
			last_coin=now_coin;
		}
		printf("%d\n",cnt);
	}
}