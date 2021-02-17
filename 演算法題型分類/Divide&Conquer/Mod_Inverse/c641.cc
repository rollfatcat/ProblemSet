// 解法概念是中國餘式定理，完成後挑戰 c637( 需要用到__int128 )
#include<bits/stdc++.h>
using namespace std;

int num[3], rem[3];
inline int InverseN(int x,int mod){
  int maxtrix[2][2]={{1,0},{0,1}};
  int num[2]={x,mod};
  bool now=0, nxt;
  for(int t; num[0] and num[1]; num[now]%=num[nxt],now=nxt){
    nxt=now^1;  t=num[now]/num[nxt];
    maxtrix[now][0]-=t*maxtrix[nxt][0],
    maxtrix[now][1]-=t*maxtrix[nxt][1];
  }
  if(maxtrix[now][0]<0)
    maxtrix[now][0]+=mod;
  return (int)maxtrix[now][0];
}
int main(){
  while(scanf("%d%d%d",&num[0],&num[1],&num[2])==3){
    scanf("%d%d%d",&rem[0],&rem[1],&rem[2]);
    int maxp=max(max(num[0],num[1]),num[2]);
    int coLCM=num[0]*num[1]*num[2];
    int LCM, sum=0;
    for(int i=0;i<3;i++)
      LCM=coLCM/num[i],
      sum+=InverseN(LCM,num[i])*LCM*rem[i];
    sum%=coLCM;
    printf("%d\n",(sum>maxp)? sum: sum+coLCM );
  }
}