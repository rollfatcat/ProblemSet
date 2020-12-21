// DP找規律
#include<iostream>
using namespace std;

int DP[77]={0};
int TopDown(int now){
  if(DP[now]==0)
    DP[now]=TopDown(now-2)+TopDown(now-3);
  return DP[now];
}
int main(){
  DP[1]=1, DP[2]=DP[3]=2;

  int n;
  while(cin>>n)
    cout<<TopDown(n)<<endl;
}