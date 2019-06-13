// 輸出最後一個從右邊數來不為0的數字
/* 初始想法：滾動陣列紀錄前一個和這一個，只紀錄題目要求的最後一位不為0的數字即可
 * (1)數論解：對於2和5的因數抽出來，一個2和一個5可以相消，最後再乘回去即可
 * (2)數論解：只需要保留後6位，因為10000以內擁有最多因數5的乘數是3125(5^5)，相乗後可能會出現0故預留6位
 * 規律解請參考：c901，範圍擴大到10^15 上述的方法皆不管用
 */

#include<iostream>
#include<vector>
using namespace std;

int digit[10]={1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int cycle2[4]={6,2,4,8}; // 2->4->8->6 => 調整一下順序即可
int lastNon0Digit(int n){
  if(n<10)  return digit[n];
  int out=1, x=n/5, y=n%5;
  for(int i=0; i<y; i++)
    out*=(n-i)%10;
  return (out*cycle2[x%4]*lastNon0Digit(x) )%10;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int n; cin>>n; )
    cout<<n<<" -> "<<lastNon0Digit(n)<<'\n';
}