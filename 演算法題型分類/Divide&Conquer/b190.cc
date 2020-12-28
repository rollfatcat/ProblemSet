/* 給定Ｎ個(必為偶數)圓盤依照河內塔規則疊放，一開始全部的圓盤都在Ａ柱，奇數的圓盤放在Ｂ柱，偶數的圓盤放在Ｃ柱
 * 過程中需要維持：大圓盤不能疊在小圓盤上方且一次只能移動一個，輸出最少的步數和移動過程？
 * 正常的河內塔函數：從 fr 柱移動１-Ｎ號圓盤到 to 柱
 * 觀察規律時可以發現每３個圓盤的移動方式為一組。
 *   為了將第Ｎ個圓盤從Ａ柱移動到Ｃ柱，需要執行正常河內塔函數(移動Ｎ-1個圓盤從Ａ柱到Ｂ柱)
 *   此時Ｎ-1號圓盤不需移動(必定已經在Ｂ柱)。
 *   再來需要將第Ｎ-2號圓盤移動到Ｃ柱，需要執行正常河內塔函數(移動Ｎ-3個圓盤從Ｂ柱到Ａ柱)
 *   子問題：移動Ｎ-2號圓盤從Ａ柱到Ｃ柱。
 */
#include<bits/stdc++.h>
using namespace std;

int N, ans=0;
void Hanoi_Normal(int now,char fr,char to,char tmp){
	if(now>1) Hanoi_Normal(now-1,fr,tmp,to);
	printf("ring %d : %c -> %c\n",now,fr,to); ans++;
	if(now>1) Hanoi_Normal(now-1,tmp,to,fr);
}
void Hanoi_Special(int now,char fr,char to,char tmp){
	if(now>1){ Hanoi_Normal(now-1,fr,tmp,to); }
	printf("ring %d : %c -> %c\n",now,fr,to); ans++;
	if(now>3){ Hanoi_Normal(now-3,tmp,fr,to); }
	if(now>2){ printf("ring %d : %c -> %c\n",now-2,tmp,to);ans++; }
	if(now>3){ Hanoi_Special(now-3,fr,tmp,to); }
}

int main(){
	while(scanf("%d",&N)!=EOF){
		ans=0;
		Hanoi_Special(N,'a','c','b');
		printf("共移動了 %d 步\n",ans);
    }
}

