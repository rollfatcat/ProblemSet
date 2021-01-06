/* 給定２個指定商品的編號和Ｎ位顧客的購物清單，輸出有幾位顧客購買紀錄包含２種指定的商品？
 * 購物清單：商品編號為０時代表清單截止，編號為正的代表拿取一件放入購物車，負的則是取出一件放回。
 * 解題關鍵：變數紀錄＋判斷式
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxA=100;
const int MaxB=100;
int cnt[MaxA+1];
int main(){
	int N, A, B, v;
	scanf("%d %d\n%d\n",&A,&B,&N);
	int ans=0;
	while(N-->0){
		fill(cnt,cnt+101,0);
		while(scanf("%d",&v) and v)
			(v>0)? cnt[v]+=1: cnt[-v]-=1;
		ans+= cnt[A]>0 and cnt[B]>0;
	}
	printf("%d\n",ans);
}