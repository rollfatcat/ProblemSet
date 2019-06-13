// 滿有意思的題目, 貪婪法=>拆出來的9越多越好
// 0額外處理, 注意輸入的大小最大需要long處理
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  long n9[12]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999,99999999999};
  int T;

  cin>>T;
  for(long n,x,other; T--; ){
    cin>>n;
    if(n==0){ cout<<0<<endl; continue; }
    int len=0, Ck=0;
    for(x=n; x>0; x/=10, len++);

    other=n-n9[len-1];
    for(x=other; x>0; Ck+=(x%10), x/=10);
    Ck+=9*(len-1);
    cout<<Ck<<endl;
  }
}
