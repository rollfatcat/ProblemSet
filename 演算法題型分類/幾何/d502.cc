// 簡單的體積計算
/* Greedy，包裝箱的邊長是４，需要最小化使用包裝箱的數量
 * 當物品的邊長是４時，需要１個包裝箱且沒有剩餘的空間
 * 當物品的邊長是３時，需要１個包裝箱且剩餘的空間可以放３７個邊長是１的物品
 * 當物品的邊長是２時，以８個一組放入１個包裝箱，剩下的空間可以拿來放邊長是１的物品
 * 前兩個剩餘空間都補放了，還有多的再拿包裝箱裝
 */
#include<iostream>
using namespace std;

int main(){

  for(int cnt[5];scanf("%d",&cnt[1])!=EOF;){
    scanf("%d %d %d",&cnt[2],&cnt[3],&cnt[4]);
    int sum=cnt[4]+cnt[3]+(cnt[2]>>3)+(bool)(cnt[2]&7);
    int cpt=37*cnt[3]+(cnt[2]-((cnt[2]>>3)<<3)<<2);
    if(cpt<cnt[1]) sum+=( (cnt[1]-cpt)>>6 )+((cnt[1]-cpt)%64==0);
    printf("%d\n",sum);
  }
}