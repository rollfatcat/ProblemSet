// 測資範圍：3 ≤ N ≤ 100，0 ≤ x,y ≤ 1024 且任兩個連續位置紀錄不會相同
// 實作細節：對向量長度『約分』時要注意正負號問題(保持dx是正的)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int,int> Count(int dx,int dy){
  if(dx==0) return (dy<0)? make_pair(0,-1): make_pair(0,1);
  if(dy==0) return (dx<0)? make_pair(-1,0): make_pair(1,0);
  int GCD=__gcd(dx,dy);
  if(dx<0) GCD=-GCD;
  return make_pair(dx/GCD,dy/GCD);
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int N, change=0;
  pair<int,int> Pnow, Pnxt, Dnow, Dnxt;
  vector<int> ans;

  cin>>N>>Pnow.first>>Pnow.second>>Pnxt.first>>Pnxt.second;
  Dnow=Count(Pnxt.first-Pnow.first, Pnxt.second-Pnow.second);
  Pnow=Pnxt;
  for(int i=2;i<N;i++){
    cin>>Pnxt.first>>Pnxt.second;
    Dnxt=Count(Pnxt.first-Pnow.first, Pnxt.second-Pnow.second);
    if(Dnxt!=Dnow) change++, ans.push_back(i);
    Pnow=Pnxt;
    Dnow=Dnxt;
  }
  cout<<change<<'\n';
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<'\n';
}
/*
5
0 0
0 1
1 1
1 0
0 0
*/