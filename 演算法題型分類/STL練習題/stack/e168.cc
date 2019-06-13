/* 經典括號配對問題：Stack應用，只是要輸出最外層除外的子字串
 * 題目的理解點：拆下包裝紙後所有商品不可為空，且所有包裝紙必須要成對配好(包括商品)
 * ({})[] => Product Broken!!
 */
#include<bits/stdc++.h>
using namespace std;

string ss, product;
stack<int> St;

inline bool CheckStack(char Lc,char Rc,int now){
  if(St.empty() or ss[St.top()]!=Lc) return false;
  int pos=St.top(); St.pop();
  if(St.empty()){
    if(now-pos==1) return false;
    else product+=ss.substr(pos+1,now-pos-1);
  }
  return true;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  while(cin>>caseT and caseT)
    while(caseT--){
      cin>>ss;

      bool safe=true;
      product="";
      for(int i=0;i<ss.length() and safe;i++){
        if(ss[i]==')')
          safe=CheckStack('(',')',i);
        else if(ss[i]=='}')
          safe=CheckStack('{','}',i);
        else if(ss[i]==']')
          safe=CheckStack('[',']',i);
        else
          St.push(i);
      }
      // 過程合法且最後Stack是空的(代表所有包裝紙都有配對形式)
      if(safe and St.empty()) cout<<product<<'\n';
      else cout<<"Product Broken!!\n";
      // stack 清空
      while(!St.empty())
        St.pop();
    }
}
/*
6
({[]})
([])([])([])
([{}]{})[()]
)(
()()()
([)]
*/