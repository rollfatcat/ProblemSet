// STL的set基礎練習，查詢某個元素是否存在，不存在就加入set(6ms)
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  set<string> Book;
  for(string ss;getline(cin,ss);){
    bool InBook=Book.count(ss);
    if(InBook==0) Book.insert(ss);
    puts( (InBook)?"YES":"NO" );
  }
}