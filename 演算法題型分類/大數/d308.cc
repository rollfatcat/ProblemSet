// 假大數 => 對單個Bit取模
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  string Nss;
  int m;
  while(cin>>Nss>>m){
    int ans=0;
    for(int i=0; i<Nss.length(); ans=ans%m)
      while(ans<m and i<Nss.length())
        ans=(ans<<3)+(ans<<1)+Nss[i++]-'0';
    cout<<ans<<endl;
  }
}