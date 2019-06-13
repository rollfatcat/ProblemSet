// STL make_pair練習：以三角形三邊當作key, 數量當作value
// 細節：判斷『合法』三角形時會做邊長相加，型態宣告是int時會導致overflow
// 直接用內建的__gcd()
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int n; cin>>n; ){
    map< pair<int,pair<int,int> >,int> table;
    int legal_data=0;
    for(long len[3]; n--; ){
      cin>>len[0]>>len[1]>>len[2];
      sort(len,len+3);
      if(len[2]>=len[1]+len[0]) continue;
      legal_data++;
      int clen=__gcd(__gcd(len[0],len[1]),len[2]);
      len[0]/=clen, len[1]/=clen, len[2]/=clen;
      table[{len[0],{len[1],len[2]}}]++;
    }
    int maxCnt=0;
    for(auto &x:table)
      maxCnt=max(maxCnt,x.second);
    cout<<legal_data<<' '<<max(0,maxCnt-1);
  }
}
