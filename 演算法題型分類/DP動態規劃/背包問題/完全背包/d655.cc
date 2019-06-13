// 1000的範圍內DP即可
#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(0),
  cin.tie(0), cout.tie(0);

  int DP[1001]={};
  int new_token[3]={30,70,110};
  for(int idx=1;idx<=1000;idx++)
    for(int num=idx; num;num/=10)
      DP[idx]+=(num%5)+((num%10)>=5);
  for(int i=0;i<3;i++)
    for(int j=new_token[i];j<=1000;j++)
      DP[j]=min(DP[j],DP[j-new_token[i]]+1);
  int T, N;
  for(cin>>T; T--;)
    cin>>N, cout<<(N/1000+DP[N%1000])<<endl;
}