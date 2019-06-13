/* 分情況討論：只有當『相遇』會發生且算出來的距離小於等於 1e18 才要輸出距離
 * 否則都是印出"position zero!"
 * 三者的輸入範圍：-1e9 ≦ Si,Pi ≦ 1e9
 * 實作細節：本題保證答案為整數，意味著在計算過程中先乘後除，避免出現問題。
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT;
  int Sk, Pk, Sh, Ph, Sm, Pm;
  const long MAXD=1e18;

  scanf("%d",&caseT);
  while(caseT--){
    scanf("%d %d %d %d %d %d",&Sk,&Pk,&Sh,&Ph,&Sm,&Pm);
    // 跑者Ｋ速度＝0 或者 跑者Ｈ和跑者Ｍ在同一個出發點
    if(Sk==0 or Ph==Pm){ puts("0"); continue; }
    // 跑者Ｈ和跑者Ｍ的速度一樣但出發點不同
    if(Sh==Sm){ puts("position zero!"); continue;}

    // (1)跑者Ｈ在跑者Ｍ的右側，只有當跑者Ｈ的速度慢於跑者Ｍ才會出現『相遇』
    // (2)跑者Ｈ在跑者Ｍ的左側，只有當跑者Ｈ的速度快於跑者Ｍ才會出現『相遇』
    if((Sh>Sm and Ph<Pm) or (Sh<Sm and Ph>Pm)){
      long disHM=abs(Ph-Pm);
      long speed=abs(Sh-Sm);
      long ans=abs(Sk*disHM)/speed; // 75% WA的關鍵(整除問題)
      if(ans>MAXD) puts("position zero!");
      else printf("%ld\n",ans);
    }else
      puts("position zero!");
  }
}