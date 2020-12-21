// DP解：前綴和版本
#include<iostream>
using namespace std;

int main(){
  long DP[31]={0,2,7,22};
  long sumDP[31]={0,2,9,31}; //前綴和
  for(int i=4;i<=30;i++)
    DP[i]=(sumDP[i-1]<<1)+DP[i-2]+2,
    sumDP[i]=sumDP[i-1]+DP[i];
  int T;  cin>>T;
  for(int k;T--;)
    cin>>k, cout<<DP[k]<<endl;
}