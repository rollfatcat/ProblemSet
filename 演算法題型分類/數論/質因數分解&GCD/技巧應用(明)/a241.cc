// 有限小數的意思就是除數只能被 2 or 5 整除
#include<iostream>
#include<vector>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int n, m;
  for(cin>>m; m--;){
    cin>>n;
    vector<int> p2, p5;
    for(int x=2;x<=n;x<<=1)
      p2.push_back(x);
    for(int x=5;x<=n;x+=(x<<2))
      p5.push_back(x);
    int cnt=p2.size()+p5.size();
    for(int i=0; i<p2.size();i++)
      for(int j=0;j<p5.size() and p2[i]*p5[j]<=n;j++)
        cnt++;
    cout<<cnt<<endl;
  }
}