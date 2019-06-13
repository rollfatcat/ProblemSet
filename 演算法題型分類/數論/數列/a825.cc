/* 先把所有數字由大至小排序，把數字依次分給當前數值較小的一個數。
 * 讓兩個數之間的差值最小化(這樣能保證乘積最大化)
 */
#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){ return a>b; }
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int num[9];
  for(int n; cin>>n; ){
    for(int i=0;i<n;i++)
      cin>>num[i];
    sort(num,num+n,compare);
    int A=0, B=0;
    for(int i=0;i<n;i++)
      if(A<B) A=10*A+num[i];
      else  B=10*B+num[i];
    cout<<A*B<<endl;
  }
}