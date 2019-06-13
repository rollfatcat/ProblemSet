// 合法字串的定義是不能是0開頭且全是由數字構成
// 字串最長是1e5個(限時1s，所以必定無法枚舉起點和終點後判斷該字串是否合法的方式)

#include<iostream>
using namespace std;

int main(){

  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT, N;
  string ss;
  cin>>caseT;
  while(caseT--){
    cin>>N>>ss;
    long long cnt=0;
    int nonzero=0;
    for(int ed=0;ed<N;ed++){
      if('0'<=ss[ed] and ss[ed]<='9'){
        cnt++;
        cnt+=nonzero;
        if(ss[ed]>'0') nonzero++;
      }
      else
        nonzero=0;
    }
    cout<<cnt<<'\n';
  }
}