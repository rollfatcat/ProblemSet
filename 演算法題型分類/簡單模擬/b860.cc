/* 給定 candy 顆糖果和 weedle 隻毛毛蟲，一隻毛毛蟲可以兌換一顆糖果，試問最多可以進化幾隻 beedrill ?
 * 進化一隻 beedrill 需要 12 顆糖果，進化後可以獲得一顆糖果且過程中可獲得兌換一顆糖果的 kakuna 。
 * 解題關鍵：簡單模擬
 * 題目盲點：題目只有描述兌換的規則，需要設計有效的兌換流程
 *         優先處理糖果足夠的情況可以直接進化，不足時再考慮從毛毛蟲換糖果。
 */
#include<iostream>
using namespace std;
 
const int MaxCandy=3e4;
const int MaxWeedle=1e4;
int main(){
	int candy, weedle, ths;
	scanf("%d %d\n",&candy,&weedle);
 
    int beedrill=0;
    // candy 足夠可以直接讓 weedle 進化為 beedrill
    while(weedle>0 and candy>=12){
        ths=min(candy/12,weedle);
        beedrill+=ths;
        candy-=ths*10;
        weedle-=ths;
    }
    /* candy 不足時則依據"多的"weedle 轉換為 candy 補足"第一次的進化條件"
     * 這次轉換後 candy 會剩下２個，每次要進化１隻 beedrill 時只需要消耗 11隻 weedle( 10隻換成candy＋1隻進化 )
     */
    if(weedle>0 and candy+weedle>12){
        beedrill+=1;
        weedle-= 13-candy;
    }
    beedrill+= weedle/11;
    printf("%d\n",beedrill);
}