// DP+Nim ：作法類似 b588 但這題還需要狀態壓縮的技巧
#include<bits/stdc++.h>
using namespace std;

int main(){
  const int maxS=1<<12;
  int one_step[24]={
    1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7, 1<<8, 1<<9, 1<<10, 1<<11,
    (1<<0)|(1<<3), (1<<3)|(1<<7), (1<<7)|(1<<10),
    (1<<1)|(1<<4), (1<<4)|(1<<8), (1<<8)|(1<<11),
    (1<<2)|(1<<3), (1<<3)|(1<<4), (1<<4)|(1<<5),
    (1<<6)|(1<<7), (1<<7)|(1<<8), (1<<8)|(1<<9)};
  bool state[maxS];
  state[0]=1;
  /* 枚舉全部的狀態nowS (0,4096)，狀態由小到大跑一次即可
   * 現在的狀態可以『還原』前一步，則把前一步的結果反轉『累疊』到現在的狀態
   */
  for(int nowS=0;nowS<maxS;nowS++)
    for(int i=0;i<24;i++)
      if((nowS&one_step[i])==one_step[i])
        state[nowS]=state[nowS]|(!state[nowS^one_step[i]]);
  // 主程式
  int N;
  for(cin>>N;N--;){
    string ss;  cin>>ss;
    int nowS=0;
    for(int i=0;i<12;i++)
      nowS+=(ss[i]-'0')<<i;
    cout<<state[nowS];
  }
  cout<<'\n';
}