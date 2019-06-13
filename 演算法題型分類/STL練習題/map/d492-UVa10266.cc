// map 模板題，且可以練習getline()和ws
// ws是跳過所有輸入前的空白
// cin >> std::ws' (ws meaning whitespace) before your calls to getline() fixes the problem
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int caseT;
  cin>>caseT>>ws;
  for(int caseN=0;caseN<caseT;caseN++){
    map<string,int> book;
    int cnt=0;
    string ss;
    while(getline(cin,ss) and ss.size())
      cnt++, book[ss]++;
    if(caseN) cout<<'\n';
    for(map<string,int>::iterator it=book.begin();it!=book.end();it++)
      cout<<fixed<<setprecision(4)<<it->first<<' '<<100.0*it->second/cnt<<'\n';
  }
}