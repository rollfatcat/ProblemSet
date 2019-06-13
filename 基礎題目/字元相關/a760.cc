/* 題目：將『連續』字串構成的日期(14碼)轉為日期，找出比2013/09/18 13:30:00 還大但最近的日期
 * 只將大小寫字母轉換取3的餘數。
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string ss;
  string ans_ss="22222222222222";
  // 每行(段)是獨立的字串，不可以合併處理。
  // 但是需要把測資全部讀完才輸出一個最佳解即可。
  while(getline(cin,ss)){
    cin>>ws;
    string number="";
    for(char ch:ss)
      if( ('A'<=ch and ch<='Z') or ('a'<=ch and ch<='z') )
        number+=(char)(ch%3+'0');
    for(int st=0;st<number.size()-13;st++){
      if(number[st+4]=='2' or number[st+4]=='0' and number[st+5]=='0') continue;
      if(number[st]<'2' or number[st]=='2' and number[st+1]=='0' and number[st+2]<='1') continue;
      string now_ss=number.substr(st,14);
      if(now_ss<ans_ss)
        ans_ss=now_ss;
    }
  }
  ans_ss=ans_ss.substr(0,4)+'/'+ans_ss.substr(4,2)+'/'+ans_ss.substr(6,2)+' '+ans_ss.substr(8,2)+':'+ans_ss.substr(10,2)+':'+ans_ss.substr(12,2);
  cout<<ans_ss<<endl;
}
