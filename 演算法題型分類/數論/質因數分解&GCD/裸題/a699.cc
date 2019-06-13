// 範圍不大, 可以建表O(1)判斷質數
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<bool> isP(671065,true);
int main(){
  // 建質數表
  int bound=sqrt(671064);
  isP[0]=isP[1]=false;
  for(int i=4;i<=671064;i+=2)
    isP[i]=false;
  for(int j=3;j<=bound;j+=2)
    if(isP[j])
      for(int i=3*j; i<=671064; i+=(j<<1))
        isP[i]=false;
  //
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  for(int n; cin>>n;)
    if(isP[n])  cout<<"It's a prime!!!\n";
    else cout<<"It's not a prime!!!\n";
}