// 匹配問題模板題，同d879-uva10911
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define NoCome 0xf7f7f7f7

int N;
int DP[1<<16];
int StatusDP(int nowS){
  if(DP[nowS]==NoCome){
    int iS=nowS&-nowS,  outS=nowS^iS;
    for(int inS=outS,jS; inS; inS^=jS )
      jS=inS&-inS,
      DP[nowS]=max(DP[nowS],StatusDP(outS^jS)+DP[iS|jS]);
  }
  return DP[nowS];
}
int main(){
  while(cin>>N){
    N<<=1;
    memset(DP,0xf7,sizeof(DP));
    for(int i=0;i<N;i++)
      for(int x,j=0;j<N;j++)
        cin>>x, DP[1<<i^1<<j]=x;
    cout<<StatusDP((1<<N)-1)*10<<endl;
  }
}