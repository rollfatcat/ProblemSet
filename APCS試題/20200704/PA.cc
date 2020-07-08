/* 給定兩個號碼ＸＹ代表產品編號、Ｍ位顧客和每位顧客的購物清單，輸出有幾位顧客都有買入ＸＹ兩項產品
 * 購物清單由一串數字構成，數值>０時代表買入某項產品，數值＜０時代表將某項產品移除購物籃，數值＝０代表清單結束
 */
#include<bits/stdc++.h>
using namespace std;

const int MaxK=100;
const int MaxT=100;
int cnt[2];

int main(){
	int X, Y, M, v, ans=0;
	scanf("%d %d\n%d\n",&X,&Y,&M);
	while(M--){
		cnt[0]=cnt[1]=0;
		while(scanf("%d",&v) and v){
			if(v== X) cnt[0]++;
			if(v==-X and cnt[0]>0) cnt[0]--;
			if(v== Y) cnt[1]++;
			if(v==-Y and cnt[1]>0) cnt[1]--;
		}
		ans+=( cnt[0]>0 and cnt[1]>0 );
	}
	printf("%d\n",ans);
}
