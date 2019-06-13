// 數學題 O(1)可解
// 觀察可以發現一個分母的必定落在 x 和 2x 之間
#include<iostream>
#include<vector>
using namespace std;

struct Pair{ int a, b; };
int main(){
  int n, LCM;
  while(cin>>n){
    int bound=n+n;
    vector<Pair>ans;
    for(int diff=1;diff<=n;diff++)
      if(n*(n+diff)%diff==0)
        LCM=n*(n+diff)/diff,
        ans.push_back({LCM,n+diff});
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
      cout<<"1/"<<n<<" = 1/"<<ans[i].a<<" + 1/"<<ans[i].b<<endl;
  }
}