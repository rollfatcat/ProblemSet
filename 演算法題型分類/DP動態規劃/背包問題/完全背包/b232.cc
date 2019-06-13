#include<iostream>
using namespace std;
#define MaxN 751

int main(){
  unsigned long long int DP[MaxN];
  fill(DP,DP+MaxN,1);
  for(int i=3;i<MaxN;i+=2)
    for(int j=i;j<MaxN;j++)
      DP[j]+=DP[j-i];
  int M, N;
  cin>>M;
  while(M--)
    cin>>N, cout<<DP[N]<<endl;
}