#include<iostream>
using namespace std;

int now;
int money[10]={1,5,10,20,50,100,200,500,1000,2000};
long long int cnt[10][50001];
long long int DP(int ks, int rem){
  if(ks<0 or rem<0) return 0;
  if(rem==0)  return 1;
  if(cnt[ks][rem]<0)
    cnt[ks][rem]=DP(ks-1, rem)+DP(ks, rem-money[ks]);
  return cnt[ks][rem];
}
int main(){
  //Top-Down
  for(int i=0;i<10;i++)
    for(int j=0;j<=50000;j++)
      cnt[i][j]=-1;
  DP(9,50000);
  int tmp, total;
  char c;
  while(scanf("%d",&total) and total){
    for(c=getchar();c!='\n';c=getchar())
      scanf("%d",&tmp), total+=tmp;
    cout<<DP(9,total)-1<<endl;
  }
}