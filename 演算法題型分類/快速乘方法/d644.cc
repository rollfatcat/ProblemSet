// 觀察找到規律：ƒ(n) = fib(n)-fib(n-1)/2
// 注意 mod的數字是100019, 因為矩陣相乘時兩個數字乘完後才取mod會超出int範圍, 要改為longlong存放
#include<iostream>
using namespace std;

int main(){

  long long int mod=100019, target;
  long long int base[2][2][2]={ {{1,1},{1,0}}, {} }, st[2][2]={{1,0},{}};
  bool now=0, nxt;
  for( cin>>target, target--; target>0; target/=2){
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
  cout<<(mod+st[0][0]-st[0][1]/2)%mod<<endl;
}