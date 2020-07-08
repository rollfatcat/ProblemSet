// 時間字串轉換成數字練習＋排序
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int TimeString(string ss){
  int i=0, Mnum=0, Snum=0, pos=ss.find(':');
  for(; i<pos; i++)
    Mnum=10*Mnum+ss[i]-'0';
  for(i=pos+1;i<ss.length();i++)
    Snum=10*Snum+ss[i]-'0';
  return Mnum*60+Snum;
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int n, t;
  string ss;
  while(cin>>n>>t){
    vector<int>team(t,0);
    for(int i=0;i<n;i++)
      for(int j=0;j<t;j++)
        cin>>ss, team[j]+=TimeString(ss);
    sort(team.begin(),team.end());
    for(auto it:team)
      cout<<it<<endl;
  }
}