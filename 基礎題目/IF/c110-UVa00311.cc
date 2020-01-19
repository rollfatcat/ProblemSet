/* 數學問題：需要根據情況討論流程，以下所有情況當２x２不夠多時可用４個１x１來補齊。
 * ６x６＝５x５＋11*１x１
 * ６x６＝４x４＋ 5*２x２ 
 * 因為４個３x３可以自成一箱所以只需考慮４的餘數
 * ６x６＝3x３x３＋1*２x２＋5*１x１
 * ６x６＝2x３x３＋3*２x２＋6*１x１
 * ６x６＝1x３x３＋5*２x２＋7*１x１
 * 因為９個２x２可以自成一箱所以只需考慮９的餘數
 * ６x６＝9x２x２
 * 因為３６個１x１可以自成一箱，若還有餘數時需要再多１個箱子來裝
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	for(int cnt[7],ans;scanf("%d",&cnt[1]);){
		scanf(" %d %d %d %d %d\n",&cnt[2],&cnt[3],&cnt[4],&cnt[5],&cnt[6]);
		if(cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]+cnt[6]==0) break;
		//
		ans=cnt[6]+cnt[5];
		cnt[1]-=11*cnt[5]; 
		if(cnt[1]<0) cnt[1]=0; 
		
		ans+=cnt[4]; 
		if(cnt[2]>=5*cnt[4])
			cnt[2]-= 5*cnt[4]; 
		else{
			cnt[1]-= 4*(5*cnt[4]-cnt[2]);
			cnt[2]=0;
			if(cnt[1]<0) cnt[1]=0;
		}
		
		ans+=(cnt[3]/4); cnt[3]%=4; ans+=(cnt[3]>0);
		if(cnt[3]==3){
			if(cnt[2]>0) cnt[2]--, cnt[1]-=5;
			else cnt[1]-=9;
		}else if(cnt[3]==2){
			if(cnt[2]>=3) cnt[2]-=3, cnt[1]-=6;
			else          cnt[1]-=6+4*(3-cnt[2]), cnt[2]=0;
		}else if(cnt[3]==1){
			if(cnt[2]>=5) cnt[2]-=5, cnt[1]-=7;
			else          cnt[1]-=7+4*(5-cnt[2]), cnt[2]=0;
		}
		if(cnt[1]<0) cnt[1]=0;
		
		ans+=(cnt[2]/9); cnt[2]%=9;
		if(cnt[2]>0) ans++, cnt[1]-=4*(9-cnt[2]);
		if(cnt[1]<0) cnt[1]=0;
		ans+=(cnt[1]/36); ans+=(cnt[1]%36>0);
		printf("%d\n",ans);
	}
}