// 01背包問題
#include<iostream>
using namespace std;

bool scanInt(int &x){ //輸入：後面一格如果是空白就繼續讀取，是換行就結束輸入
  char ch; for(x=0; (ch=getchar())>='0' and ch<='9'; x=(x<<3)+(x<<1)+ch-'0');
  return ch==' ';
}
int DP[1000001]={};
int main(){
  int w[1000], v[1000], L, cnt;
  for( cnt=0; scanInt(w[cnt++]); );
  for( cnt=0; scanInt(v[cnt++]); );
  scanInt(L);
  for(int i=0; i<cnt; i++)
    for(int j=L; j>=w[i]; j--)
      DP[j]=max(DP[j],DP[j-w[i]]+v[i]);
  cout<<DP[L]<<endl;
}