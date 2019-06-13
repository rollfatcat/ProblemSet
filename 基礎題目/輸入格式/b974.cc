// 練習使用 gteline() 讀取一整行後搭配 stringstream 劃分每個字串
#include<bits/stdc++.h>
using namespace std;

int main(){

  int quesNum, teamNum, team;
  cin>>quesNum>>teamNum>>ws;

  vector<int> score(teamNum+1,0);
  string line, ans, gues;
  for(int i=1;i<=quesNum;i++){
    getline(cin,line);
    stringstream ss(line);

    bool getPoint=true;
    for(ss>>ans; ss>>team>>gues; )
      if(gues==ans and getPoint)
        getPoint=false,
        score[team]++;
  }
  vector<int> winner;
  for(int maxs=0,i=1;i<=teamNum;i++){
    if(score[i]>maxs)  maxs=score[i], winner.clear();
    if(score[i]==maxs) winner.push_back(i);
  }
  cout<<winner[0];
  for(int i=1;i<winner.size();i++)
    cout<<' '<<winner[i];
  cout<<endl;
  // 輸出每隊的分數
  for(int i=1;i<=teamNum;i++)
    cout<<i<<' '<<score[i]<<endl;
}
/*
3 5
twice 1 once 2 orange 3 twice
cheer 3 up 4 baby 5 baby 2 cheer
up 2 aoa 3 2pm 4 up
*/