/*
(1)將字串轉換推進數字
(2)可以得到整場球賽的過程(依照順序紀錄是球員的推進數)
(3)可以根據三個出局數切割
(4)模擬球賽 清空壘包，打者出現安打，壘包的人推進
*/

#include<iostream>
using namespace std;
// SO=三振出局 Strike out
// GO=滾地出局 Ground out
// FO=飛球出局 Fly out
int TurnAction(string ss){
  if(ss[1]=='O')
    return 0;
  else if(ss[1]=='R')
    return 4;
  return ss[0]-'0';
}
int act[100];
int main(void){
  int num, bound, total_act=0;
  string ss;
  for(int i=0;i<9;i++){
    cin>>num;
    total_act+=num;
    for(int j=0;j<num;j++)
      cin>>ss, act[9*j+i]=TurnAction(ss);
  }
  cin>>bound;
  //
  int point=0, player=0;
  int onBase[4], num_onBase;
  while(bound){
    num_onBase=0;
    for(int out=3; out>0 and bound>0; out--,bound--,player++){
      // 如果有擊出安打
      while(act[player]){
        //打者上壘
        onBase[num_onBase++]=0;
        for(int i=0;i<num_onBase;i++)
          onBase[i]+=act[player];
        // 計算得分,超過4壘的跑者要計入得分,shift陣列內未滿4壘的跑者
        int i=0;
        while(i<num_onBase and onBase[i]>=4)
          i++;
        int rem=i;
        for(int j=i;j<num_onBase;j++)
          onBase[j-i]=onBase[j];
        point+=rem;
        num_onBase-=rem;
        player++;
      }
    }
  }
  cout<<point<<endl;
}