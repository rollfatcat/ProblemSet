// 題目的規則寫得很簡短(但很難懂=ˇ=)
// 請參考討論區的留言說明：https://zerojudge.tw/ShowThread?postid=10786
// 理解利用二維陣列模擬狀態轉換的方式

#include<iostream>
using namespace std;

int map[8][8]={
  {0,0,0,0,0,0,0,0},
  {0,1,2,3,4,5,6,7},
  {0,1,2,2,2,2,2,2},
  {0,1,3,3,4,3,3,3},
  {0,1,4,3,4,4,4,4},
  {0,1,2,3,4,5,6,7},
  {0,1,2,3,4,5,6,7},
  {0,1,2,3,4,5,6,7}
};
int main(){
  int T, status;
  string ss;
  cin>>T;
  while(T--){
    cin>>ss;
    status=1;
    for(int i=0;i<ss.length();i++)
      status=map[status][ss[i]-'0'];
    cout<<status<<endl;
  }
}