/* 給定Ｎ個紙牌堆的張數(保證可以均分)，搬動紙牌時只從搬移到左右兩堆視為一次，問最少的搬動次數？
 * 解題關鍵：貪婪
 * 當目前排堆的張數低於平均時向右邊的牌堆「借牌」，(高於平均時借的張數是負的)代表搬動一次
 * 由左而右掃描一次，確認借牌的次數發生幾次？
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxN=1e2;
const int MaxA=1e4;
int N, num[MaxN];
int main(){
	int avg=0;
	
	scanf("%d",&N);
	for(int i=0;i<N;i+=1){
		scanf("%d",&num[i]);
		avg+=num[i];
	}
	avg/=N;
	int dif, ans=0;
	for(int i=1;i<N;i+=1){
		dif=avg-num[i-1];
		ans+= dif!=0;
		num[i]-=dif;	
	}
	printf("%d\n",ans);
}