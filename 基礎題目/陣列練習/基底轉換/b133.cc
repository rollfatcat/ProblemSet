// 觀察題目講到由小到大的部分可以發現這題其實是不同進位單位轉換問題
// 題目雖然保證測資在運算過程不會超過 int 範圍，但最後一筆測資其實會(#9: 13 600)
// 需要 AC 的話單位記得還是以 int 紀錄(long算出來是對的但會吃 WA )
#include<bits/stdc++.h>
using namespace std;

int main(){
  for(int k,n;scanf("%d %d",&k,&n)==2;){
    int sum=(n&1)?1:0;
    int base=k;
    for(n>>=1;n;n>>=1,base*=k)
      if(n&1)
        sum+=base;
    printf("%d\n",sum);
  }
}