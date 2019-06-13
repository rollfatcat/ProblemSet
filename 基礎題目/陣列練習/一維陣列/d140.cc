// 接在 d786之後，講解浮點數導致精確度問題
// 字串讀入, 題目沒說但是測資給的時候固定會給到小數點後兩位的精確度
// 請不要用浮點數讀入,會失真
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for(string ss; cin>>ss; ){
    int len=ss.length();
    int m=(ss[len-1]-'0')+10*(ss[len-2]-'0')+100*(ss[len-4]-'0');
    for(int i=len-5, base=1000;i>=0;i--)
      m+=base*(ss[i]-'0'),  base*=10;
    if(m<10000) m=m*0.9+800;
    else if(m<50000)  m*=0.8;
    else m*=0.6;
    printf("$%d.%02d\n",m/100,m%100);
  }
}