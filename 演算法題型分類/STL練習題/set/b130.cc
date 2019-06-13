// set的STL練習 => 不重複且會排序 => 和c421那題的multiset比較
#include<iostream>
#include<set>
using namespace std;

int main(){
  set<int> S;
  int n, x;
  for(cin>>n; n--; )
    cin>>x, S.insert(x);
  cout<<S.size()<<endl;
  for(auto it:S)
    cout<<it<<' ';
  cout<<endl;
}