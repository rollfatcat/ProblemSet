// 最小化二次方程式：
// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4112808#reply_div_3169387
/* 假設停在x樓，則不滿意度總和：(x-2)+...+1+0+ 2*(1+...+(k-x-1))=(x-2)(x-1)/2+(k-x+1)(k-x)
 * 對 x 配方可以取得最小直落在 x=(4k+5)/6
 */
#include<iostream>
using namespace std;
#define esp 1e-4

int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  for(long k,k1,k2; cin>>k; ){
    k1=((k<<2)+5)/6, k2=k1+1;
    long sumk1=(k1-2)*(k1-1)/2+(k-k1+1)*(k-k1);
    long sumk2=(k2-2)*(k2-1)/2+(k-k2+1)*(k-k2);
    if(sumk1==sumk2) printf("%ld %ld\n",k1,k2);
    else if(sumk1>sumk2) printf("%ld\n",k2);
    else printf("%ld\n",k1);
  }
}