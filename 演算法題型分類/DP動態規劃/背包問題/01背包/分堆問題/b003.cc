// 題解：https://home.gamer.com.tw/creationDetail.php?sn=4156133
// 乍看之下是枚舉每個數字決定是正負號，好像是01背包問題的變形(分堆問題)
// 但實際上是貪婪法去逼近 N
#include<iostream>
#include<cmath>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(long n; cin>>n;){
    if(n<0) n=-n;
    int num=sqrt(n<<1);
    if(num*(num+1)/2<n) num++;
    for(long x=num*(num+1)/2; (x&1)!=(n&1); num++,x=num*(num+1)/2);
    cout<<num<<endl;
  }
}