// 用算的不需要模擬
#include<iostream>
using namespace std;
#define INF 0x7fffffff

int main(){
  int hp[2], atk[2], dfs[2], dps[2], live[2];

  while(cin>>hp[0]>>atk[0]>>dfs[0]>>hp[1]>>atk[1]>>dfs[1] and hp[0]){
    dps[0]=(atk[0]-dfs[1]>0)?(atk[0]-dfs[1]):0;
    dps[1]=(atk[1]-dfs[0]>0)?(atk[1]-dfs[0]):0;
    live[0]=(dps[1]>0)?(hp[0]/dps[1]+(hp[0]%dps[1]>0)):INF,
    live[1]=(dps[0]>0)?(hp[1]/dps[0]+(hp[1]%dps[0]>0)):INF;
    if(live[0]>=live[1]) cout<<"You win in "<<live[1]<<" round(s)."<<endl;
    else cout<<"You lose in "<<live[0]<<" round(s)."<<endl;
  }
}