// Bottom-Up來做,只是用兩個一維陣列交替
// 時間64ms, 但問題是不知道記憶體可以用更少的方法
#include<iostream>
#include<vector>
using namespace std;
#define MaxN 33

vector<string> LCS[2][MaxN];
string s1, s2;
bool nxt, pre;

void Union(int now){
  LCS[nxt][now].clear();
  int i=0, j=0;
  while(i<LCS[nxt][now-1].size() and j<LCS[pre][now].size())
    if(LCS[nxt][now-1][i]==LCS[pre][now][j])
      LCS[nxt][now].push_back( LCS[nxt][now-1][i] ),  i++, j++;
    else if(LCS[nxt][now-1][i]>LCS[pre][now][j])
      LCS[nxt][now].push_back( LCS[pre][now][j++] );
    else
      LCS[nxt][now].push_back( LCS[nxt][now-1][i++] );
  while(i<LCS[nxt][now-1].size())
    LCS[nxt][now].push_back(LCS[nxt][now-1][i++]);
  while(j<LCS[pre][now].size())
    LCS[nxt][now].push_back(LCS[pre][now][j++]);
}
int main(){
  int T;
  cin>>T;
  for(int caseNum=1;caseNum<=T;caseNum++){
    cin>>s1>>s2;

    for(int i=0;i<=s2.length();i++)
      LCS[0][i].clear(), LCS[0][i].push_back(""),
      LCS[1][i].clear(), LCS[1][i].push_back("");
    pre=1, nxt=0;
    for(int i=0;i<s1.length();i++){
      pre=pre^1, nxt=nxt^1;
      for(int j=0;j<s2.length();j++)
        if(s2[j]==s1[i]){
          LCS[nxt][j+1].clear();
          for(int k=0;k<LCS[pre][j].size();k++)
            LCS[nxt][j+1].push_back(LCS[pre][j][k]+s1[i]);
        }else{
          if(LCS[pre][j+1][0].length()==LCS[nxt][j][0].length())
            Union(j+1);
          else if(LCS[pre][j+1][0].length()>LCS[nxt][j][0].length())
            LCS[nxt][j+1].assign(LCS[pre][j+1].begin(),LCS[pre][j+1].end());
          else
            LCS[nxt][j+1].assign(LCS[nxt][j].begin(),LCS[nxt][j].end());
        }
    }
    cout<<"Case #"<<caseNum<<": "<<LCS[nxt][s2.length()].size()<<endl;
    for(int i=0;i<LCS[nxt][s2.length()].size();i++)
      cout<<LCS[nxt][s2.length()][i]<<endl;
  }
}