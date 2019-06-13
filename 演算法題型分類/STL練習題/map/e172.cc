// 若 1,3,5下在同一點，則需要輸出：1 = 3 = 5

#include<bits/stdc++.h>
using namespace std;
#define MAXN 20

short GoMap[MAXN][MAXN];
vector<short> line[500];
int main(){
  int N, x, y;
  while(cin>>N and N){
    memset(GoMap,0,sizeof(GoMap));
    map<pair<short,short>,short> memo;
    int team, teamNum=0;
    for(int i=1;i<=N;i++){
      cin>>x>>y;
      if(GoMap[x][y]){ // 紀錄落子點重複時的隊伍編號
        team=memo[make_pair(x,y)],
        line[team].push_back(i);
      }
      else // 標記落子的時間點，且在memo紀錄對應的隊伍編號
        GoMap[x][y]=i,
        memo[make_pair(x,y)]=teamNum,
        line[teamNum].clear(),
        line[teamNum].push_back(i),
        teamNum++;
    }
    // 因為輸出二維陣列的順序和(數學的二維座標平面不同)，需要自行調整
    for(int i=19;i>0;i--,cout<<endl)
      for(int j=1;j<=19;j++)
        cout<<GoMap[j][i]<<' ';
    // 依照重複的情況輸出第Ｎ手和哪一次出現重複
    for(int i=0;i<teamNum;i++){
      if(line[i].size()==1) continue;
      cout<<line[i][0];
      for(int j=1;j<line[i].size();j++)
        cout<<" = "<<line[i][j];
      cout<<endl;
    }
  }
}