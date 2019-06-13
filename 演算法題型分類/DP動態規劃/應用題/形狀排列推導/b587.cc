// 題目故意不給 ƒ(4) 和 ƒ(6) 就是要自己推導狀態
/* ƒ(2) = 3
 * ƒ(4) = 3xƒ(2)+2 = 11
 * ƒ(6) = 3xƒ(4)+2xƒ(2)+2 = 41
 * ƒ(8) = 3xƒ(6)+2xƒ(4)+2xƒ(2)+2 = 153
 */
#include<iostream>
using namespace std;

int main(){
  int DP[31]={1,0,3};
  for(int i=4;i<=30;i+=2){
    for(int j=0;j<i;j+=2)
      DP[i]+=(DP[j]<<1);
    DP[i]+=DP[i-2];
  }
  for(int n; cin>>n and n>=0; )
    cout<<DP[n]<<endl;
}
/* ƒ(2)=3
 a b   c c   a a
 a b   a b   b b
 c c   a b   c c
   ƒ(4)=11 多的2種
 a a b b   c e e f
 c d d f   c d d f
 c e e f   a a b b
*/