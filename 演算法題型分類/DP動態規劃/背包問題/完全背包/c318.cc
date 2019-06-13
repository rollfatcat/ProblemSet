// 其實和無限背包無關，只做為對照題目被放在這邊
// 題目要取前T個得分高的，但是每個章節得分會因為邊界效益遞減
/* 解法:排序所有大於0的章節得分取前T高的即可...
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  for(int N,T; cin>>N>>T;){
    vector<int> score;
    for(int x,y; N--; )
      for(cin>>x>>y; x>0; x-=y)
        score.push_back(x);
    sort(score.begin(),score.end());
    int sum=0, l=score.size();
    for(int i=1;i<=T;i++)
      sum+=score[l-i];
    cout<<sum<<'\n';
  }
}