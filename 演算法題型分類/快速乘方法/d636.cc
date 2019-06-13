// 二進位轉換的進階應用：快速求得次方
// 1<=base<=65535, 要先取一次餘數確保不會超過int上限
#include<iostream>
using namespace std;

int main(){
  int base, power, ans, now;
  scanf("%d%d",&base,&power);
  for(ans=1,base=base%10007; power>0; power/=2, base=base*base%10007)
    if(power%2)
      ans=ans*base%10007;
  printf("%d\n",ans);
}