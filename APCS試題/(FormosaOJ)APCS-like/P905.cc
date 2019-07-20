/* 第一行是一個整數 T 代表測試資料數量。每一筆測資都是一行後綴表示法。
 * 運算子只會有 '+' 和 '*'，數字只會是非負整數。並且數字與數字間會有一個以上的空白，
 * 數字與運算子、運算子與運算子之間則是會有零個以上的空白。
 * 保證式子是合理的後綴表示法且運算過程中的數字不會超過1e18。
 * 每一行的字元數不會超過2000000個
 * 3
 * 1000000000 1000000000 *
 * 1 2 3+4**
 * 2 3 4   + *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
  int caseT;
  string ss;

  cin>>caseT>>ws;
  while(caseT--){
    getline(cin,ss);
    stack<long> S;
    long number=0, calc;
    bool InNumber=false;

    for(int i=0;i<ss.length();i++){
      if('0'<=ss[i] and ss[i]<='9')
        InNumber=true,
        number=(number<<3)+(number<<1)+ss[i]-'0';
      else{
        if(InNumber)
          S.push(number),
          InNumber=number=0;
        if(ss[i]=='*') calc=S.top(), S.pop(), S.top()*=calc;
        if(ss[i]=='+') calc=S.top(), S.pop(), S.top()+=calc;
      }
    }
    cout<<S.top()<<endl;
  }
}