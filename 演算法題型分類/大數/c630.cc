// 大數(?)比大小
// 數論：求a^n的大小 => 取10為log底數比較
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct nn{ int a,n; double l; };
bool compare(nn x,nn y){ return x.l>y.l; }
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  vector<nn> num;
  for(int a, n; cin>>a>>n; )
    num.push_back({a,n,log10(a)*n});
  sort(num.begin(),num.end(),compare);
  for(int i=0;i<num.size();i++)
    cout<<num[i].a<<' '<<num[i].n<<endl;
}