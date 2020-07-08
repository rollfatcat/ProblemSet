// 不需要暴力去排列，類似c471: apcs 物品堆疊 (Stacking)，難在往前排的規則
// 一樣長，就直接比，但若不一樣長(假設s1,s2)，則將(s1+s2)與(s2+s1)來比
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b){ return (a+b)>(b+a); }
int main(){
  cin.sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(int n; cin>>n; ){
    vector<string> unit;
    string ss;
    for(int i=0;i<n;i++)
      cin>>ss,  unit.push_back(ss);
    sort(unit.begin(),unit.end(),compare);
    for(int i=0;i<n;i++)
      cout<<unit[i];
    cout<<endl;
  }
}