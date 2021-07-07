/* 給定６種規格箱子的數量，輸出最少需要多少個６×６的大箱子才能裝入所有不同規格的小箱子？
 * 箱子的規格：高度相同但底面積為正方形的邊長不同，邊長長度從１到６。
 * 解題關鍵：處理流程設計
 * 需要根據情況討論流程(有多餘的空間可以再放入比自已邊長小的箱子時優先討論)
 * 以下所有情況當２x２不夠多時可用４個１x１來補齊：
 * (1) ５×５、４x４、３×３
 * (2) ２×２
 * (3) １×１
 */
#include<bits/stdc++.h>
using namespace std;

int box[7];
int coff[4][2]={{},{5,7},{3,6},{1,5}};
inline void PackOne(int need){
	box[1]= (box[1]>=need)? box[1]-need: 0;
}
inline void PackTwo(int need){
	if(box[2]>=need){
		box[2]-=need;
	}else{
		PackOne( 4*(need-box[2]) );
		box[2]=0;
	}
}
int main(){
	int ans, rem;
	while(scanf("%d %d %d ",&box[1],&box[2],&box[3])){
		scanf("%d %d %d ",&box[4],&box[5],&box[6]);
		if(box[1]+box[2]+box[3]+box[4]+box[5]+box[6]==0) break;
		
		ans=box[6];
		/* 因為４個３x３可以自成一箱所以只需考慮４的餘數時需要搭配２×２和１×１的情況：
		 * ６x６＝４*３x３
		 * ６x６＝３*３x３＋１*２x２＋５*１x１
		 * ６x６＝２*３x３＋３*２x２＋６*１x１
		 * ６x６＝１*３x３＋５*２x２＋７*１x１
		 */
		rem =box[3]%4;
		ans+=box[3]/4+ (rem>0);
		PackTwo(coff[rem][0]);
		PackOne(coff[rem][1]);
		/* ６x６＝１*４x４＋５*２x２ */
		ans+=box[4];
		PackTwo(5*box[4]);
		/* ６x６＝１*５x５＋１１*１x１ */
		ans+=box[5];
		PackOne(11*box[5]);
		
		/* 因為９個２x２可以自成一箱所以只需考慮９的餘數
		 * ６x６＝９*２x２
		 */
		rem =box[2]%9;
		ans+=box[2]/9+ (rem>0);
		PackTwo(rem);
		/* 因為３６個１x１可以自成一箱所以只需考慮３６的餘數
		 * ６x６＝３６*１x１
		 */
		ans+=box[1]/36+ (box[1]%36>0);
		
		printf("%d\n",ans);
	}
}