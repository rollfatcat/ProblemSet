// DP入門, 最小化區段合併成本
#include<iostream>
#include<cstring>
using namespace std;
#define MaxN 52

int L, N, C[MaxN], DP[MaxN][MaxN];
int TopDown(int l, int r){
  if(r-l<=1)  return 0;
  if(DP[l][r]==0x7f7f7f7f)
    for(int i=l+1;i<r;i++)
      DP[l][r]=min(DP[l][r],TopDown(l,i)+TopDown(i,r)+C[r]-C[l]);
  return DP[l][r];
}
int main(){
  while(cin>>L and L){
    cin>>N;
    for(int i=1;i<=N;i++)
      cin>>C[i];
    C[0]=0, C[N+1]=L;
    memset(DP,0x7f,sizeof(DP));
    cout<<"The minimum cutting is "<<TopDown(0,N+1)<<".\n";
  }
}