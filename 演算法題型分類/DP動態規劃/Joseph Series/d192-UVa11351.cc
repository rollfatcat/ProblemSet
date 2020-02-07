// 只算最後一個倖存者可以由DP回推
#include<iostream>
using namespace std;

//  號碼從0開始算
int main(){
    ios::sync_with_stdio(0),  cin.tie(0);

    int T, n, m, f=0;
    cin>>T;
    for(int t=1;t<=T;t++){
      cin>>n>>m;
      for(int i=1; i<=n; i++)
        f=(f+m)%i;
      printf("Case %d: %d\n",t,f+1);
    }
}