// 測資輸入說明有誤，必須讀取到三個字串時才計算
// 考慮最高位相加後的『進位』，有的話要多出一個字元'B'
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string ss[2];
  while(cin>>ss[0]>>ss[0]>>ss[1]){
    int carry=0;
    for(int i=ss[0].length()-1;i>=0;i--){
      ss[0][i]=ss[0][i]+ss[1][i]-'A'+carry;
      if(ss[0][i]>'Z') ss[0][i]-=26, carry=1;
      else carry=0;
    }
    if(carry) cout<<'B';
    cout<<ss[0]<<'\n';
  }
}