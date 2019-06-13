// 只跑一次從1出發 找到的答案都存起來
// Time：76ms, 記憶體：8.6M
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<string> DP[401];
string numToss[29]={"0","1","2","3","4","5","6","7","8","9",
                    "10","11","12","13","14","15","16","17","18","19",
                    "20","21","22","23","24","25","26","27","28"};
void DFS(string ss, int score, int now){
  if(score+now>400)  return;
  ss+=(" + "+numToss[now]);
  score+=now;
  DP[score].push_back(ss);
  DFS(ss,score,now+1);
  for(int i=2*score;i<=400;i*=2)
    ss+=" * 2",
    DP[i].push_back(ss),
    DFS(ss,i,now+1);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string ss="1";
  DP[1].push_back(ss);
  DFS(ss,1,2);
  for(int i=2;i<=400;i*=2)
    ss+=" * 2",
    DP[i].push_back(ss),
    DFS(ss,i,2);

  int n;
  while(cin>>n and n){
    if(DP[n].size()==0)
      cout<<"cheat!\n";
    else
      for(int i=0;i<DP[n].size();i++)
        cout<<DP[n][i]<<'\n';
  }
}