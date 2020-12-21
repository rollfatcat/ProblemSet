// 矩陣連乘的DP求最小合併Cost，類似d686
#include<iostream>
#include<cstring>
using namespace std;
#define INF 0x7f7f7f7f

int N, num[50], DP[50][50];
int TopDown(int l,int r){
  if(r-l<2) return 0;
  if(DP[l][r]==INF)
    for(int mid=l+1;mid<r;mid++)
      DP[l][r]=min(DP[l][r],TopDown(l,mid)+TopDown(mid,r)+num[l]*num[mid]*num[r]);
  return DP[l][r];
}
int main(){
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>num[i];
  memset(DP,0x7f,sizeof(DP));
  cout<<TopDown(0,N-1)<<endl;
}
/*  1 2 3 4 5  |  0
 *  1 3 4 5    |  6
 *  1 4 5      | 18
 *  1 5        | 38
 */