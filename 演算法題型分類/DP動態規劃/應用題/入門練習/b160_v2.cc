#include<iostream>
using namespace std;
#define MaxN 300001

int DP[MaxN]={0};
int main(){
  int M, S, T, m, i;

  cin>>M>>S>>T;
  m=M;
  for(i=1;i<=T;i++){
    if(m>=10) DP[i]=DP[i-1]+60, m-=10;
    else      DP[i]=DP[i-1], m+=4;
  }
  for(i=1;i<=T;i++){
    DP[i]=max(DP[i], DP[i-1]+17);
    if(DP[i]>=S){
      cout<<"Yes"<<endl<<i<<endl; return 0;
    }
  }
  cout<<"No"<<endl<<DP[T]<<endl;
}