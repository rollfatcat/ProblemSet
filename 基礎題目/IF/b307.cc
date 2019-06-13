/* 讀懂題目的說明，並注意輸入的測資計算過程中會出現overflow(如果是宣告成int)
 * 1 ≦ a, b ≦ 1000，1 ≦ q ≦ 100000000
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT;
  long a, b, q;

  scanf("%d",&caseT);
  while(caseT--)
    scanf("%ld %ld %ld",&a,&b,&q),
    puts( ((a*q%10007)==(b*q%10007))?"SAFE":"BOOM" );
}