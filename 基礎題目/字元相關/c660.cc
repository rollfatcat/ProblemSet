// 字串練習 字元大小寫轉換和陣列位置
// 輸入包含空白，需要getline()，轉換大小寫時前一個字元可能是空白
#include<bits/stdc++.h>
using namespace std;

int main(){
  string ss;
  while(getline(cin,ss)){
    for(int i=0;i<ss.length();i++)
      if(ss[i]>='A' and ss[i]<='Z')
        ss[i]+='a'-'A';
    int now=0, pre;
    while(ss[now]==' ') now++;
    ss[now]+='A'-'a';
    cout<<ss<<'\n';
    for(pre=now++;now<ss.length();now++){
      if(ss[now]==' ') continue;
      // 跳過空白時，要記錄前一個位置把大寫轉成小寫
      ss[pre]+='a'-'A';
      ss[now]+='A'-'a';
      cout<<ss<<'\n';
      pre=now;
    }
  }
}