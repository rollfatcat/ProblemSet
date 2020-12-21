// 解法來源：https://miohitokiri5474.blogspot.com/2018/07/toj406-c.html
// 狀態壓縮的DP解
#include<iostream>
#include<cstring>
using namespace std;

int DP[4][1<<3]={0};
int main(){
  int N, c;
  long cnt=0;
  bool a,r,d;
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);
  for(cin>>N; N--;)
    cin>>c>>a>>r>>d,  DP[c][(a<<2)+(r<<1)+d]++;
  for(int Hs=0;Hs<8;Hs++)
    for(int Ks=0;Ks<8;Ks++)
      for(int Gs=0;Gs<8;Gs++)
        if((Hs|Ks|Gs)==7)
          cnt+=DP[1][Hs]*DP[2][Ks]*DP[3][Gs];
  cout<<cnt<<endl;
}