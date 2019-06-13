// 這題無法先將二進位的數字轉成十進位之後再判斷能不能被三整除
// 題目最多會給9000位的二進位輸入
// 透過觀察『被三整除』的條件後可以知道將奇數位數和偶數位數拆開來看

#include<iostream>
#include<cstring>
using namespace std;

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int T;
  for(cin>>T;T--;){
    string ss;  cin>>ss;
    int A=0, B=0;
    for(int i=0;i<ss.length();i++)
      if(i&1) B+=(ss[i]-'0');
      else A+=(ss[i]-'0');
    int sum=A+(B<<1);
    if(sum%3) puts("No");
    else puts("Yes");
  }
}