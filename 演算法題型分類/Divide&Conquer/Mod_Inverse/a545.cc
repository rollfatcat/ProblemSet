// 不要用 scanInt的方式讀取會跳出 SIGBUS的問題(題目給的字元間可能不只一個空白)
// 數論題(找出同餘情形下的乘法反元素)
// 演算筆記：http://www.csie.ntnu.edu.tw/~u91029/Residue.html
/* 除一個數字，相當於乘上他的乘法反元素。
 * 逆元的求法可以使用 gcd 的擴展歐幾里德定理 (因為 1,0000,0007 是個質數)。
 */
#include<iostream>
using namespace std;
#define MaxN 1001
#define MOD 100000007

long inverseP(long x){ // MOD是一個質數 => inverse必定存在
  long maxtrix[2][2]={{1,0},{0,1}}, num[2]={x,MOD};
  bool now=0, nxt;
  for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
    nxt=now^1;  t=num[now]/num[nxt];
    maxtrix[now][0]-=t*maxtrix[nxt][0],
    maxtrix[now][1]-=t*maxtrix[nxt][1];
  }
  return (maxtrix[now][0]<0)?(maxtrix[now][0]+MOD):maxtrix[now][0];
}
int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  long p[MaxN][MaxN], inv;
  for(int m,n,cnt; cin>>m>>n and m; ){
    long mul=1;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>p[i][j], p[i][j]%=MOD, mul=(mul*p[i][j])%MOD;
    /* a÷b ≡ a*inv(b) ≡ x (mod m) */
    for(cin>>cnt; cnt--;)
      cin>>m>>n,  cout<<(mul*inverseP(p[--m][--n])%MOD)<<endl;
  }
}
