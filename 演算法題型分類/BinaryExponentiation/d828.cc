// Fib的快速幂次
// 1 1 2 3 5 8 ...
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  int mod=10000, target;
  while(cin>>target){
    int base[2][2][2]={ {{1,1},{1,0}}, {} }, st[2][2]={{1,0},{}};
    bool now=0, nxt;
    for( ;target>0; target/=2){
      if(target%2){
        st[1][0]=(base[now][0][0]*st[0][0]+base[now][0][1]*st[0][1])%mod;
        st[1][1]=(base[now][1][0]*st[0][0]+base[now][1][1]*st[0][1])%mod;
        st[0][0]=st[1][0],  st[0][1]=st[1][1];
      }
      nxt=now^1;
      base[nxt][0][0]=(base[now][0][0]*base[now][0][0]+base[now][0][1]*base[now][1][0])%mod;
      base[nxt][0][1]=(base[now][0][0]*base[now][0][1]+base[now][0][1]*base[now][1][1])%mod;
      base[nxt][1][0]=(base[now][1][0]*base[now][0][0]+base[now][1][1]*base[now][1][0])%mod;
      base[nxt][1][1]=(base[now][1][0]*base[now][0][1]+base[now][1][1]*base[now][1][1])%mod;
      now=nxt;
    }
    cout<<st[0][0]<<endl;
  }
}